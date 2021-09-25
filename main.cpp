#include <stdio.h>
#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
#include <vector>
#include <string> 
#include <omp.h>


using namespace cv;
using namespace std;

int main(int argc, char** argv )
{
    if ( argc < 2 ){
        cout<<"Faltan argumentos\n"<<endl;
        cout<<"---INTEGRANTES---\n"<<endl;
        cout<<"Manuel Toledo Levican\n";
        cout<<"Byron Diaz Jara\n";
        cout<<"Branislav Vecka Muñoz\n";
        return-1;
    }

    else if(argc > 3){
        cout<<"sobran argumentos\n"<<endl;
        cout<<"---INTEGRANTES---\n"<<endl;
        cout<<"Manuel Toledo Levican\n";
        cout<<"Byron Diaz Jara\n";
        cout<<"Branislav Vecka Muñoz\n";
        return -1;
    }

    if(argc = 3){
        //if(argv[1]termina en ".jpg")
        
        //carga imagen en escala de grises
        Mat orig = imread( argv[1], 0 );
        
        string salida = argv[2];

        namedWindow("Original", WINDOW_AUTOSIZE );
        cv::imshow("Original", orig);
        


        int filas = 0;
        filas = orig.rows;
    
        int cols = 0;
        cols = orig.cols;

        Mat color (orig.rows, orig.cols, CV_8UC3);
        Mat neg (orig.rows, orig.cols, CV_8UC3);
        


#pragma omp parallel num_threads(2)
        for (int i = 0; i <= filas-1; i++){
        
            uchar *p = orig.ptr<uchar>(i);
            //uchar *n = orig.ptr<uchar>(i);
	        uchar temp;
            
            #pragma omp parallel for    
	        for (int j = 0; j <= cols-1; j++){

                temp = *(p + j);
                
				    if (0 <= temp && temp <= 63){

					    color.at<cv::Vec3b>(i, j)[0] = (255-(255-temp));//B
					    color.at<cv::Vec3b>(i, j)[1] = 255-(254 - 4 * temp);//G
					    color.at<cv::Vec3b>(i, j)[2] = 255-(254 - 4 * temp);//R

                        neg.at<cv::Vec3b>(i, j)[0] = abs(255 - color.at<cv::Vec3b>(i, j)[0]);
                        neg.at<cv::Vec3b>(i, j)[1] = abs(255 - color.at<cv::Vec3b>(i, j)[1]);
                        neg.at<cv::Vec3b>(i, j)[2] = abs(255 - color.at<cv::Vec3b>(i, j)[2]);
				    }
				    
                    else if (64 <= temp && temp <= 127){

					    color.at<cv::Vec3b>(i, j)[0] = 255-(510-4*temp);//B
					    color.at<cv::Vec3b>(i, j)[1] = 255-abs(524 - 4 * temp);//G
					    color.at<cv::Vec3b>(i, j)[2] = 255-abs(510 - 4 * temp);//R

                        neg.at<cv::Vec3b>(i,j)[0] = abs(255 - color.at<cv::Vec3b>(i, j)[0]);
                        neg.at<cv::Vec3b>(i,j)[1] = abs(255 - color.at<cv::Vec3b>(i, j)[1]);
                        neg.at<cv::Vec3b>(i,j)[2] = abs(255 - color.at<cv::Vec3b>(i, j)[2]);
				    }
				    
                    else if (128 <= temp && temp <= 191){
					    color.at<cv::Vec3b>(i, j)[0] = 255-(255-temp);//B
					    color.at<cv::Vec3b>(i, j)[1] = 255-abs(255-temp);//G
					    color.at<cv::Vec3b>(i, j)[2] = 255-(255-(4*temp - 510));//R

                        neg.at<cv::Vec3b>(i,j)[0] = abs(255 - color.at<cv::Vec3b>(i, j)[0]);
                        neg.at<cv::Vec3b>(i,j)[1] = abs(255 - color.at<cv::Vec3b>(i, j)[1]);
                        neg.at<cv::Vec3b>(i,j)[2] = abs(255 - color.at<cv::Vec3b>(i, j)[2]);
				    }
				    else if (192 <= temp && temp <= 255){
					    color.at<cv::Vec3b>(i, j)[0] = 255 - abs(temp-255);//B
					    color.at<cv::Vec3b>(i, j)[1] = 255 - abs(temp-255);//G
					    color.at<cv::Vec3b>(i, j)[2] = 255 - abs(temp-255);//R

                        neg.at<cv::Vec3b>(i,j)[0] = abs(255 - color.at<cv::Vec3b>(i, j)[0]);
                        neg.at<cv::Vec3b>(i,j)[1] = abs(255 - color.at<cv::Vec3b>(i, j)[1]);
                        neg.at<cv::Vec3b>(i,j)[2] = abs(255 - color.at<cv::Vec3b>(i, j)[2]);
				    }
	        }
        }
    
        Mat prueba = color;
        //cv::merge(prueba, neg);
    
        imwrite(salida + "resultado.png",color);
        cv::imshow("color", color);
        cv::imshow("negativo", neg);
        //cv::imshow("prueba", prueba);
        
        cout<<"\n-----INTEGRANTES-----\n"<<endl;
        cout<<"- Manuel Toledo Levican\n";
        cout<<"- Byron Diaz Jara\n";
        cout<<"- Branislav Vecka Muñoz\n";
        
        cv::waitKey(0);
    }

    return 0;

}