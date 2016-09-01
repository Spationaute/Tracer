#include "imageout.hpp"

bool writeImage(imagefile image, char* to_file){
	//Check if the file already exist
	FILE* out_file;
	out_file = fopen(to_file,"r");
	
	//If the file exit, abort sequence
	if(out_file!=NULL){
		printf("File exist!\n");
		return 0;
	}

	//If reached file doesn't exist 
	//or it's not accessible
	
	//Open the file you named, and overide it
	out_file = fopen(to_file,"w");
	
	//Check if the file is really opened
	if(out_file!=NULL){

		//Write the magic number widht and height in plain ASCII
		fprintf(out_file, "P6\n%i %i\n255\n",image.width, image.height);

		//Get the image size then write it
		size_t image_size = image.width * image.height;
		for(int i=0;i<image.height;++i){
			for(int j=0;j<image.width;++j){
				int num = (i*image.width)+j;
				uint8_t* val=(uint8_t*)&(image.pixels[num]);
				val+=2;
				for (int k = 0; k < 3; ++k)
				{
					fwrite(val-k,1,sizeof(uint8_t),out_file);
				}
				//fprintf(out_file,"%i %i %i\t",val[2] ,val[1] ,val[0]);
			}
			//fprintf(out_file, "\n");
		}
		
		//Close the file
		fclose(out_file);

		//Everything is ok
		return 1;
	}

	printf("Unable to open the file");
	//Something gone wrong
	return 0; 
}