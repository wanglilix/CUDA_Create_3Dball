#include "cuda_runtime.h"  
#include "device_launch_parameters.h"  
  
#include <stdio.h>
#include <math.h>
#define Sphere_Num 100//球个数：若200 cuda核函数会崩溃
__constant__ int Sphere_Center_Device[Sphere_Num*3];
//__constant__ int Radius_Device [Sphere_Num];

__global__ void addKernel(int w,int h,int start,int end,int SphereNum,int * Radius_Device ,int * PictureBlock)  //不要在一个cpp文件中声明__device__和__global__函数
{
	int x = blockIdx.x;				//w
	int y = blockIdx.y;				//h
	int z = threadIdx.x + start ;
	PictureBlock[threadIdx.x*w*h + y*w + x] = 0 ;

	for (int k = 0 ;k < SphereNum ; ++k)//对每个球     判断（i，j，z）是否在球内    //不能在大循环中定义变量
 	{
		int xdistance2 = blockIdx.x - Sphere_Center_Device[k*3] ;
	    int ydistance2 = blockIdx.y - Sphere_Center_Device[k*3+1];
		int zdistance2 = threadIdx.x + start - Sphere_Center_Device[k*3+2];
		int tmp = ydistance2 * ydistance2 + xdistance2*xdistance2 +zdistance2* zdistance2;
		int  r = Radius_Device[k]*Radius_Device[k];
		if (tmp < r)
		{
			PictureBlock[threadIdx.x*w*h + y*w + x] = 255 ;
		}
	}
}





extern "C" 
cudaError_t addWithCuda(int w,int h,int start,int end,int SphereNum,int* Sphere_Center,int *Radius_ ,int * PictureBlock)
{
	cudaError_t cudaStatus;

	//int * Sphere_Center_Device = 0;
	int * Radius_Device		 = 0;
	int * Picture_Block_Device = 0;

	//cudaStatus = cudaMalloc((void**)&Sphere_Center_Device, SphereNum*3*sizeof( int)     );  
	cudaStatus = cudaMalloc((void**)&Radius_Device,        SphereNum*sizeof( int)       );
	cudaStatus = cudaMalloc((void**)&Picture_Block_Device, (end-start+1)*w*h*sizeof(int));

	//cudaMemcpy((void*)(Sphere_Center_Device), (void*)(Sphere_Center), SphereNum*3*sizeof( int), cudaMemcpyHostToDevice);
	cudaMemcpy((void*)( Radius_Device      ), (void*)(Radius_      ), SphereNum*sizeof( int)  , cudaMemcpyHostToDevice);

	cudaMemcpyToSymbol(Sphere_Center_Device,Sphere_Center,sizeof(int)*SphereNum*3);
	//cudaMemcpyToSymbol(Radius_Device       ,Radius_      ,sizeof(int)*SphereNum);


	if (cudaStatus != cudaSuccess) {  
        fprintf(stderr, "cudaMalloc failed! ");  
        goto Error;  
    } 

	dim3 blocks(w,h);
	dim3 threads(end-start+1);//RealPicNum
	addKernel<<<blocks,threads >>>(w,h,start,end,SphereNum,Radius_Device,Picture_Block_Device);



	cudaMemcpy((void*)(PictureBlock), (void*)(Picture_Block_Device),(end-start+1)*w*h*sizeof(int), cudaMemcpyDeviceToHost);

	cudaStatus = cudaGetLastError();
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "addKernel launch failed: %s\n", cudaGetErrorString(cudaStatus));  
        goto Error;  
    }


Error:
	//cudaFree(Sphere_Center_Device);
	cudaFree(Radius_Device);
	cudaFree(Picture_Block_Device);


	return cudaStatus;
}
