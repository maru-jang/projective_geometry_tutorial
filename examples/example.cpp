//#include "module1/ClassEigen.hpp"

#include "Eigen/Dense"
#include "Eigen/Geometry"

#include <iostream>
#include<cmath>

int main() {

    // Matrix initialization method 1
    Eigen::Matrix<double,2,3> matrix23_double;
    matrix23_double << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0;

    // Matrix initialization method 2
    Eigen::Matrix3d matrix33_double = Eigen::Matrix3d::Zero();

    // Matrix initialization method 3
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic;

    // Vector initialization method 1
    Eigen::Vector3d vec = {1.0, 2.0, 3.0};

    // Vector initialization method 2
    Eigen::Vector3d vec_zeros = Eigen::Vector3d::Zero();

    Eigen::Matrix3d mat33;
    mat33 << 1.0, 2.0, 3.0,
            4.0, 5.0, 6.0,
            7.0, 8.0, 9.0;

    for (int row = 0; row < mat33.rows(); ++row)
    {
        for (int col = 0; col < mat33.cols(); ++col)
        {
            std::cout << mat33(row,col) << std::endl;
        }
    }

    //Rotation 45 degrees along z axis
    Eigen::AngleAxisd rotation_vector(M_PI/4.0, Eigen::Vector3d(0.0,0.0,1.0));

    std::cout << "rotation vector = " << std::endl;
    std::cout << rotation_vector.matrix() << std::endl;
    std::cout << std::endl;

    Eigen::Vector3d vector(1.0,0.0,0.0);
    Eigen::Vector3d rotated_vector = rotation_vector * vector;

    std::cout << "rotated vector = " << std::endl;
    std::cout << rotated_vector.transpose() << std::endl;

    //Rotate 45 degrees along z-axis
    Eigen::Quaterniond quat = Eigen::Quaterniond(rotation_vector);

    std::cout << "quaternion = " << quat.coeffs().transpose() << std::endl;
    std::cout << std::endl;

    std::cout << "rotated vector = " << (quat * vector).transpose() << std::endl;


    return 0;

}

