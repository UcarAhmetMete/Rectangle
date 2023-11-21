//
// Created by Ahmet Mete Ucar on 19/11/23.
//

#include <stdio.h>
#include <string.h>
#define SZ 30
typedef struct{
    char name[SZ];
    double length;
    double width;
    double area;
    double perimeter;
} Rectangle;



int main(){
    FILE *fileIn = fopen("test1.txt", "r");  // I have opened the files I need.
    FILE *fileArea= fopen("filearea.txt", "w");
    FILE *filePerimeter = fopen("filePerimeter2.txt", "w");

    if(fileIn == NULL || fileArea == NULL || filePerimeter == NULL){   // I checked if the files are working right or not.
        fprintf(stderr, "Error opening files/n");
         return 1;
    }

    Rectangle rectangle[15];
    int numRectangles = 0; // We must be sure we have three arguments here the name, width and length not more than this.
    while(fscanf(fileIn, "%s %lf %lf", rectangle[numRectangles].name, &rectangle[numRectangles].length,&rectangle[numRectangles].width) == 3){
        rectangle[numRectangles].area = rectangle[numRectangles].length * rectangle[numRectangles].width; // I calculated the area
        rectangle[numRectangles].perimeter = 2*(rectangle[numRectangles].length + rectangle[numRectangles].width); // I calculated the perimeter
        numRectangles++; // And then, I incremented the numRectangles to calculate other recatangles.

        if(numRectangles >= 15) {  // I used this because I just have 10 rectangles in my file and no need more than this amount. I have defined a close number to 10
            fprintf(stderr,"too many rectangles");
            break; // If there is more then it will break the loop
        }
    }
    for(int i = 0; i < numRectangles -1; i++){    // This the classic  selection sort algorithm to sort all rectangles
        for (int j = i+1; j <  numRectangles; j++){
            if(rectangle[i].area < rectangle[j].area){
                Rectangle temp = rectangle[i];
                rectangle[i] = rectangle[j];
                rectangle[j] = temp;
            }
        }
    }
    for (int i = 0; i < numRectangles; i++) {
        fprintf(fileArea, "%s %lf\n", rectangle[i].name, rectangle[i].area);  // This is where we print the values
    }


    for (int i = 0; i < numRectangles-1; i++ ){
        for (int j = i+1; j< numRectangles; j++ ){
            if(rectangle[i].perimeter < rectangle[j].perimeter){
                Rectangle temp2 = rectangle[i];
                rectangle[i] = rectangle[j];
                rectangle[j] = temp2;
            }
        }
    }

    for (int i = 0 ; i , numRectangles; i ++){
        fprintf(filePerimeter, "%s %lf\n", rectangle[i].name, rectangle[i].perimeter);
    }

    fclose(fileIn);
    fclose(fileArea);
    fclose(filePerimeter);
    return 0;
}
