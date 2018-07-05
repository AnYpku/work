#include <iostream>  

void MultiplyWithOutAMP() {  

//    double aMatrix[3][3] = {{13700, 1480,2670}, {0.0000533, 14.7,831}, {0.025, 11500,9250}};  
    double aMatrix[3][3] = {{117.032, 554.89,75.6227}, {0.00376, 33.2618,1.32753}, {0.2189, 771.551,134.943}};  
//    double bMatrix[3][3] = {{0.00854, 0.029,0.0041}, {0.0000156, 0.0354,0.0106}, {0.00000425, 0.0394,0.00141}};  
    double bMatrix[3][1] = {{78000}, {6300}, {7000}};  
//    double bMatrix[3][1] = {{0.48}, {0.3}, {0.013}};  
    double product[3][1] = {{0}, {0}, {0}};  
//    double product[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};  

    for (int row = 0; row < 3; row++) {  
        for (int col = 0; col < 1; col++) {  
            // Multiply the row of A by the column of B to get the row, column of product.  
            for (int inner = 0; inner < 3; inner++) {  
                product[row][col] += aMatrix[row][inner] * bMatrix[inner][col];  
            }  
            std::cout << product[row][col] << "  ";  
        }  
        std::cout << "\n";  
    }  
}  

int main() {  
    MultiplyWithOutAMP();  
    getchar();  
    return 0;
}  
