//
// Created by Andrew Knee on 10/17/2020.
//

#ifndef CLOCKWORKENGINE_DEFAULTCOMPONENTS_H
#define CLOCKWORKENGINE_DEFAULTCOMPONENTS_H

#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/glm.hpp>
#include <array>
#include "glad/glad.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace ClockworkEngine {
    /**
     * A Transform class for which the 3D data is taken from to determine characteristics of model.
     */
    struct Transform {
        /**
         * Creates a quaternion from 3 euler angles.
         * @param angle Vec3 containing the euler angles in form {x, y, z} in degrees.
         * @return Quaternion created from the 3 euler angles. Optional return. Automatically
         *      updates the quaternion stored in the struct.
         */
        glm::quat degreeToQuat(const glm::vec3 &angle);

        /**
         * Creates a quaternion from 3 euler angles.
         * @param quatRotation Quaternion for which the rotation is stored.
         * @param angle Vec3 containing the euler angles in form {x, y, z} in degress.
         * @return Quaternion created from the 3 euler angles.
         */
        static void degreeToQuat(glm::quat &quatRotation, const glm::vec3 &angle);

        /**
         * Creates a quaternion from 3 euler angles.
         * @param angle Vec3 containing the euler angles in form {x, y, z} in radians.
         * @return Quaternion created from the 3 euler angles. Optional return. Automatically
         *      updates the quaternion stored in the struct.
         */
        glm::quat radiansToQuat(const glm::vec3 &angle);

        /**
         * Creates a quaternion from 3 euler angles.
         * @param quatRotation Quaternion for which the rotation is stored.
         * @param angle Vec3 containing the euler angles in form {x, y, z} in radians.
         * @return Quaternion created from the 3 euler angles.
         */
        static void radiansToQuat(glm::quat &quatRotation, const glm::vec3 &angle);

        /**
         * Creates a quaternion from a rotation axis and the orientation around that axis.
         * @param rotationRads Float of the rotation around the axis in radians.
         * @param rotationAxis Vec3 of the rotation axis in form {x, y, z}.
         * @return Quaternion created from the axes and angle. Optional return. Automatically
         *      updates the quaternion stored in the struct.
         */
        glm::quat axisToQuat(const float &rotationRads, const glm::vec3 &rotationAxis);

        /**
         * Creates a quaternion from a rotation axis and the orientation around that axis.
         * @param quatRotation Quaternion for which the rotation is stored.
         * @param rotationRads Float of the rotation around the axis in radians.
         * @param rotationAxis Vec3 of the rotation axis in form {x, y, z}.
         * @return Quaternion created from the axes and angle.
         */
        static void axisToQuat(glm::quat &quatRotation, const float &rotationRads, const glm::vec3 &rotationAxis);

        /**
         * Converts quaternion stored in struct into a 4x4 matrix.
         * @return Mat4 constructed from quaternion.
         */
        glm::mat4 toMat4() const;

        /**
         * Converts quaternion into a 4x4 matrix.
         * @param quaternion Quaternion to convert to Mat4.
         * @return Mat4 constructed from quaternion.
         */
        static glm::mat4 toMat4(const glm::quat &quaternion);

        /**
         * Converts quaternion stored in struct into a Vec3 or euler angles.
         * @return Vec3 of euler angles in form {x, y, z}.
         */
        glm::vec3 toEuler() const;

        /**
         * Converts quaternion into a Vec3 or euler angles.
         * @param quatRotation Quaternion to convert to Vec3.
         * @return Vec3 of euler angles in form {x, y, z}.
         */
        static glm::vec3 toEuler(const glm::quat &quatRotation);

        const glm::vec3 &getPosition() const;

        const glm::quat &getQuatRotation() const;

        const glm::vec3 &getScale() const;

        void setPosition(const glm::vec3 &position);

        void setQuatRotation(const glm::quat &quatRotation);

        void setScale(const glm::vec3 &scale);

        void setVisibility(bool visible);

        bool &isVisible();

    private:
        glm::vec3 position = glm::vec3(0.0);
        glm::quat quatRotation = glm::quat(0.0, 0.0, 0.0, 0.0); //x = roll, y = pitch, z = yaw
        glm::vec3 scale = glm::vec3(0.0);

        bool visible = true;
    };


    /**
     * Stores all relevant physics information of 3D rigidbody.
     * Used in conjunction with transform for which the variables in here are set in the transform.
     */
    struct RigidBody {
        /**
         * Creates a quaternion from 3 euler angles.
         * @param angle Vec3 containing the euler angles in form {x, y, z} in degrees.
         * @return Quaternion created from the 3 euler angles. Optional return. Automatically
         *      updates the quaternion stored in the struct.
         */
        glm::quat degreeToQuat(const glm::vec3 &angle);

        /**
         * Creates a quaternion from 3 euler angles.
         * @param rotation Quaternion for which the rotation is stored.
         * @param angle Vec3 containing the euler angles in form {x, y, z} in degress.
         * @return Quaternion created from the 3 euler angles.
         */
        static void degreeToQuat(glm::quat &rotation, const glm::vec3 &angle);

        /**
         * Creates a quaternion from 3 euler angles.
         * @param angle Vec3 containing the euler angles in form {x, y, z} in radians.
         * @return Quaternion created from the 3 euler angles. Optional return. Automatically
         *      updates the quaternion stored in the struct.
         */
        glm::quat radiansToQuat(const glm::vec3 &angle);

        /**
         * Creates a quaternion from 3 euler angles.
         * @param rotation Quaternion for which the rotation is stored.
         * @param angle Vec3 containing the euler angles in form {x, y, z} in radians.
         * @return Quaternion created from the 3 euler angles.
         */
        static void radiansToQuat(glm::quat &rotation, const glm::vec3 &angle);

        /**
         * Creates a quaternion from a rotation axis and the orientation around that axis.
         * @param rotationRads Float of the rotation around the axis in radians.
         * @param rotationAxis Vec3 of the rotation axis in form {x, y, z}.
         * @return Quaternion created from the axes and angle. Optional return. Automatically
         *      updates the quaternion stored in the struct.
         */
        glm::quat axisToQuat(const float &rotationRads, const glm::vec3 &rotationAxis);

        /**
         * Creates a quaternion from a rotation axis and the orientation around that axis.
         * @param rotation Quaternion for which the rotation is stored.
         * @param rotationRads Float of the rotation around the axis in radians.
         * @param rotationAxis Vec3 of the rotation axis in form {x, y, z}.
         * @return Quaternion created from the axes and angle.
         */
        static void axisToQuat(glm::quat &rotation, const float &rotationRads, const glm::vec3 &rotationAxis);

        /**
         * Converts quaternion stored in struct into a 4x4 matrix.
         * @return Mat4 constructed from quaternion.
         */
        glm::mat4 toMat4() const;

        /**
         * Converts quaternion into a 4x4 matrix.
         * @param quaternion Quaternion to convert to Mat4.
         * @return Mat4 constructed from quaternion.
         */
        static glm::mat4 toMat4(const glm::quat &quaternion);

        /**
         * Converts quaternion stored in struct into a Vec3 or euler angles.
         * @return Vec3 of euler angles in form {x, y, z}.
         */
        glm::vec3 toEuler() const;

        /**
         * Converts quaternion into a Vec3 or euler angles.
         * @param rotation Quaternion to convert to Vec3.
         * @return Vec3 of euler angles in form {x, y, z}.
         */
        static glm::vec3 toEuler(const glm::quat &rotation);

        /**
         * Updates the velocity based on the set acceleration and timestep.
         * @param dt Float timestep.
         */
        void updateVelocity(const float dt);

        /**
         * Updates the angular velocity based on the set angular acceleration and timestep.
         * @param dt Float timestep.
         */
        void updateAngularVelocity(const float dt);

        /**
         * Updates the position based on the set velocity and timestep.
         * @param dt Float timestep.
         */
        void updatePosition(const float dt);

        /**
         * Updates the rotation based on the set angular velocity and timestep.
         * @param dt Float timestep.
         * @return Vec3& of the updated rotation.
         */
        void updateRotation(const float dt);

        void applyForce(const glm::vec3 &force);

        const glm::vec3 &getVelocity() const;

        const glm::vec3 &getPosition() const;

        const glm::quat &getRotation() const;

        const glm::vec3 &getAngularVelocity() const;

        const glm::vec3 &getAcceleration() const;

        const glm::vec3 &getAngularAcceleration() const;

        const float &getMass() const;

        void setVelocity(const glm::vec3 &velocity);

        void setPosition(const glm::vec3 &position);

        void setRotation(const glm::quat &rotation);

        void setAngularVelocity(const glm::vec3 &angularVelocity);

        void setAcceleration(const glm::vec3 &acceleration);

        void setAngularAcceleration(const glm::vec3 &angularAcceleration);

        void setMass(const float &mass);

    private:
        glm::vec3 velocity;
        glm::vec3 position;
        glm::quat rotation; //x = roll, y = pitch, z = yaw
        glm::vec3 angularVelocity;
        glm::vec3 acceleration;
        glm::vec3 angularAcceleration;

        float mass;
    };

    /**
     * Contains the mesh data.
     * Stores the Vec3 of vertices, normals, and the pairing of vertices to create polygons.
     */
    struct Mesh {
        /**
         * Generates rectangular mesh of size width, height. Orientated on x, y axis;
         * @param width Integer for width of rectangle.
         * @param height Integer for height of rectangle.
         */
        void generateRectangularMesh(int width, int height);

        /**
         * Sets the vertices stored in the object.
         * @param vertices Vec3 array of the vertex vectors.
         * @param length Integer of the length of the array.
         */
        void setVertices(glm::vec3 vertices[], int length);

        /**
         * Sets the normals stored in the object.
         * @param normals Vec3 array of the normal vectors.
         * @param length Integer of the length of the array.
         */
        void setNormals(glm::vec3 normals[], int length);

        /**
         * Sets the order of the vertices stored in the object.
         * @param orderOfVertices Vec3 array of the order of the vertices.
         *      Vec3 consists of indices of the vertices from the original array.
         * @param length Integer of the length of the array.
         */
        void setOrderOfVertices(glm::ivec3 orderOfVertices[], int length);

        int getVerticesSize();

        int getNormalsSize();

        int getOrderSize();

        /**
         * Returns an array of vertices.
         * @tparam N Integer of the array. Gotten by using associated getSize function.
         * @return std::array of vertices.
         */
        template<int N>
        std::array<glm::vec3, N> getVertices();

        /**
         * Returns an array of normals.
         * @tparam N Integer of the array. Gotten by using associated getSize function.
         * @return std::array of normals.
         */
        template<int N>
        std::array<glm::vec3, N> getNormals();

        /**
         * Returns an array of order of vertices.
         * @tparam N Integer of the array. Gotten by using associated getSize function.
         * @return std::array of the order of vertices.
         */
        template<int N>
        std::array<glm::ivec3, N> getOrder();

        /**
         * Deletes the pointers.
         */
        ~Mesh();

    private:
        int verticesSize = 0, normalsSize = 0, orderOfVerticesSize = 0;
        glm::vec3 *vertices;
        glm::vec3 *normals;
        glm::ivec3 *orderOfVertices;
    };

    struct Shader
    {
        //program id
        unsigned int ID;

        //reads and builders shader
        Shader(const char* vertexPath, const char* fragmentPath);
        ~Shader();
        //activate shader
        void use();

        void setBool(const std::string &name, bool value) const;
        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;
        void setVec2(const std::string &name, const glm::vec2 &value) const;
        void setVec2(const std::string &name, float x, float y) const;
        void setVec3(const std::string &name, const glm::vec3 &value) const;
        void setVec3(const std::string &name, float x, float y, float z) const;
        void setVec4(const std::string &name, const glm::vec4 &value) const;
        void setVec4(const std::string &name, float x, float y, float z, float w) const;
        void setMat2(const std::string &name, const glm::mat2 &mat) const;
        void setMat3(const std::string &name, const glm::mat3 &mat) const;
        void setMat4(const std::string &name, const glm::mat4 &mat) const;

    private:
        void checkCompileErrors(unsigned int shader, std::string type);
    };

    struct Texture{
        
    };
}

#endif //CLOCKWORKENGINE_DEFAULTCOMPONENTS_H
