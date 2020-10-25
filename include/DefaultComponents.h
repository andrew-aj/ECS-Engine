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
        glm::quat degreeToQuat(const glm::vec3 &angle) {
            quatRotation = glm::quat(glm::radians(angle));
            return quatRotation;
        }

        /**
         * Creates a quaternion from 3 euler angles.
         * @param quatRotation Quaternion for which the rotation is stored.
         * @param angle Vec3 containing the euler angles in form {x, y, z} in degress.
         * @return Quaternion created from the 3 euler angles.
         */
        static void degreeToQuat(glm::quat &quatRotation, const glm::vec3 &angle) {
            quatRotation = glm::quat(glm::radians(angle));
        }

        /**
         * Creates a quaternion from 3 euler angles.
         * @param angle Vec3 containing the euler angles in form {x, y, z} in radians.
         * @return Quaternion created from the 3 euler angles. Optional return. Automatically
         *      updates the quaternion stored in the struct.
         */
        glm::quat radiansToQuat(const glm::vec3 &angle) {
            quatRotation = glm::quat(angle);
            return quatRotation;
        }

        /**
         * Creates a quaternion from 3 euler angles.
         * @param quatRotation Quaternion for which the rotation is stored.
         * @param angle Vec3 containing the euler angles in form {x, y, z} in radians.
         * @return Quaternion created from the 3 euler angles.
         */
        static void radiansToQuat(glm::quat &quatRotation, const glm::vec3 &angle) {
            quatRotation = glm::quat(angle);
        }

        /**
         * Creates a quaternion from a rotation axis and the orientation around that axis.
         * @param rotationRads Float of the rotation around the axis in radians.
         * @param rotationAxis Vec3 of the rotation axis in form {x, y, z}.
         * @return Quaternion created from the axes and angle. Optional return. Automatically
         *      updates the quaternion stored in the struct.
         */
        glm::quat axisToQuat(const float &rotationRads, const glm::vec3 &rotationAxis) {
            quatRotation = glm::angleAxis(rotationRads, rotationAxis);
            return quatRotation;
        }

        /**
         * Creates a quaternion from a rotation axis and the orientation around that axis.
         * @param quatRotation Quaternion for which the rotation is stored.
         * @param rotationRads Float of the rotation around the axis in radians.
         * @param rotationAxis Vec3 of the rotation axis in form {x, y, z}.
         * @return Quaternion created from the axes and angle.
         */
        static void axisToQuat(glm::quat &quatRotation, const float &rotationRads, const glm::vec3 &rotationAxis) {
            quatRotation = glm::angleAxis(rotationRads, rotationAxis);
        }

        /**
         * Converts quaternion stored in struct into a 4x4 matrix.
         * @return Mat4 constructed from quaternion.
         */
        glm::mat4 toMat4() const {
            return glm::toMat4(quatRotation);
        }

        /**
         * Converts quaternion into a 4x4 matrix.
         * @param quaternion Quaternion to convert to Mat4.
         * @return Mat4 constructed from quaternion.
         */
        static glm::mat4 toMat4(const glm::quat &quaternion) {
            return glm::toMat4(quaternion);
        }

        /**
         * Converts quaternion stored in struct into a Vec3 or euler angles.
         * @return Vec3 of euler angles in form {x, y, z}.
         */
        glm::vec3 toEuler() const {
            return glm::eulerAngles(quatRotation);
        }

        /**
         * Converts quaternion into a Vec3 or euler angles.
         * @param quatRotation Quaternion to convert to Vec3.
         * @return Vec3 of euler angles in form {x, y, z}.
         */
        static glm::vec3 toEuler(const glm::quat &quatRotation) {
            return glm::eulerAngles(quatRotation);
        }

        const glm::vec3 &getPosition() const {
            return position;
        }

        const glm::quat &getQuatRotation() const {
            return quatRotation;
        }

        const glm::vec3 &getScale() const {
            return scale;
        }

        void setPosition(const glm::vec3 &position) {
            Transform::position = position;
        }

        void setQuatRotation(const glm::quat &quatRotation) {
            Transform::quatRotation = quatRotation;
        }

        void setScale(const glm::vec3 &scale) {
            Transform::scale = scale;
        }

        void setVisibility(bool visible){
            Transform::visible = visible;
        }

        bool &isVisible(){
            return visible;
        }

    private:
        glm::vec3 position;
        glm::quat quatRotation;
        glm::vec3 scale;

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
        glm::quat degreeToQuat(const glm::vec3 &angle) {
            rotation = glm::quat(glm::radians(angle));
            return rotation;
        }

        /**
         * Creates a quaternion from 3 euler angles.
         * @param rotation Quaternion for which the rotation is stored.
         * @param angle Vec3 containing the euler angles in form {x, y, z} in degress.
         * @return Quaternion created from the 3 euler angles.
         */
        static void degreeToQuat(glm::quat &rotation, const glm::vec3 &angle) {
            rotation = glm::quat(glm::radians(angle));
        }

        /**
         * Creates a quaternion from 3 euler angles.
         * @param angle Vec3 containing the euler angles in form {x, y, z} in radians.
         * @return Quaternion created from the 3 euler angles. Optional return. Automatically
         *      updates the quaternion stored in the struct.
         */
        glm::quat radiansToQuat(const glm::vec3 &angle) {
            rotation = glm::quat(angle);
            return rotation;
        }

        /**
         * Creates a quaternion from 3 euler angles.
         * @param rotation Quaternion for which the rotation is stored.
         * @param angle Vec3 containing the euler angles in form {x, y, z} in radians.
         * @return Quaternion created from the 3 euler angles.
         */
        static void radiansToQuat(glm::quat &rotation, const glm::vec3 &angle) {
            rotation = glm::quat(angle);
        }

        /**
         * Creates a quaternion from a rotation axis and the orientation around that axis.
         * @param rotationRads Float of the rotation around the axis in radians.
         * @param rotationAxis Vec3 of the rotation axis in form {x, y, z}.
         * @return Quaternion created from the axes and angle. Optional return. Automatically
         *      updates the quaternion stored in the struct.
         */
        glm::quat axisToQuat(const float &rotationRads, const glm::vec3 &rotationAxis) {
            rotation = glm::angleAxis(rotationRads, rotationAxis);
            return rotation;
        }

        /**
         * Creates a quaternion from a rotation axis and the orientation around that axis.
         * @param rotation Quaternion for which the rotation is stored.
         * @param rotationRads Float of the rotation around the axis in radians.
         * @param rotationAxis Vec3 of the rotation axis in form {x, y, z}.
         * @return Quaternion created from the axes and angle.
         */
        static void axisToQuat(glm::quat &rotation, const float &rotationRads, const glm::vec3 &rotationAxis) {
            rotation = glm::angleAxis(rotationRads, rotationAxis);
        }

        /**
         * Converts quaternion stored in struct into a 4x4 matrix.
         * @return Mat4 constructed from quaternion.
         */
        glm::mat4 toMat4() const {
            return glm::toMat4(rotation);
        }

        /**
         * Converts quaternion into a 4x4 matrix.
         * @param quaternion Quaternion to convert to Mat4.
         * @return Mat4 constructed from quaternion.
         */
        static glm::mat4 toMat4(const glm::quat &quaternion) {
            return glm::toMat4(quaternion);
        }

        /**
         * Converts quaternion stored in struct into a Vec3 or euler angles.
         * @return Vec3 of euler angles in form {x, y, z}.
         */
        glm::vec3 toEuler() const {
            return glm::eulerAngles(rotation);
        }

        /**
         * Converts quaternion into a Vec3 or euler angles.
         * @param rotation Quaternion to convert to Vec3.
         * @return Vec3 of euler angles in form {x, y, z}.
         */
        static glm::vec3 toEuler(const glm::quat &rotation) {
            return glm::eulerAngles(rotation);
        }

        /**
         * Updates the velocity based on the set acceleration and timestep.
         * @param dt Float timestep.
         */
        void updateVelocity(const float dt) {
            velocity += acceleration * dt;
        }

        /**
         * Updates the angular velocity based on the set angular acceleration and timestep.
         * @param dt Float timestep.
         */
        void updateAngularVelocity(const float dt) {
            angularVelocity += angularAcceleration * dt;
        }

        /**
         * Updates the position based on the set velocity and timestep.
         * @param dt Float timestep.
         */
        void updatePosition(const float dt) {
            position += velocity * dt;
        }

        /**
         * Updates the rotation based on the set angular velocity and timestep.
         * @param dt Float timestep.
         * @return Vec3& of the updated rotation.
         */
        void updateRotation(const float dt) {
            rotation = radiansToQuat(toEuler() + (angularVelocity * dt));
        }

        void applyForce(const glm::vec3 &force) {
            acceleration = force / mass;
        }

        const glm::vec3 &getVelocity() const {
            return velocity;
        }

        const glm::vec3 &getPosition() const {
            return position;
        }

        const glm::quat &getRotation() const {
            return rotation;
        }

        const glm::vec3 &getAngularVelocity() const {
            return angularVelocity;
        }

        const glm::vec3 &getAcceleration() const {
            return acceleration;
        }

        const glm::vec3 &getAngularAcceleration() const {
            return angularAcceleration;
        }

        const float &getMass() const {
            return mass;
        }

        void setVelocity(const glm::vec3 &velocity) {
            RigidBody::velocity = velocity;
        }

        void setPosition(const glm::vec3 &position) {
            RigidBody::position = position;
        }

        void setRotation(const glm::quat &rotation) {
            RigidBody::rotation = rotation;
        }

        void setAngularVelocity(const glm::vec3 &angularVelocity) {
            RigidBody::angularVelocity = angularVelocity;
        }

        void setAcceleration(const glm::vec3 &acceleration) {
            RigidBody::acceleration = acceleration;
        }

        void setAngularAcceleration(const glm::vec3 &angularAcceleration) {
            RigidBody::angularAcceleration = angularAcceleration;
        }

        void setMass(const float &mass) {
            RigidBody::mass = mass;
        }

    private:
        glm::vec3 velocity;
        glm::vec3 position;
        glm::quat rotation;
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
        void generateRectangularMesh(int width, int height) {
            delete[] vertices;
            delete[] normals;
            delete[] orderOfVertices;
            verticesSize = (width + 1) * (height + 1);
            vertices = new glm::vec3[verticesSize];
            int index = 0;
            for (int i = 0; i <= height; i++) {
                for (int j = 0; j <= width; j++) {
                    vertices[index] = glm::vec3(j, i, 0);
                }
            }

            orderOfVerticesSize = width * height * 2;
            orderOfVertices = new glm::ivec3[orderOfVerticesSize];
            int tris = 0, vert = 0;
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    orderOfVertices[tris] = glm::ivec3(vert + 0, vert + width + 1, vert + 1);
                    orderOfVertices[++tris] = glm::ivec3(vert + 1, vert + width + 1, vert + width + 2);
                    tris++;
                    vert++;
                }
                vert++;
            }
            //TODO implement normals
        }

        /**
         * Sets the vertices stored in the object.
         * @param vertices Vec3 array of the vertex vectors.
         * @param length Integer of the length of the array.
         */
        void setVertices(glm::vec3 vertices[], int length) {
            delete[] Mesh::vertices;
            Mesh::vertices = vertices;
            verticesSize = length;
            vertices = nullptr;
        }

        /**
         * Sets the normals stored in the object.
         * @param normals Vec3 array of the normal vectors.
         * @param length Integer of the length of the array.
         */
        void setNormals(glm::vec3 normals[], int length) {
            delete[] Mesh::normals;
            Mesh::normals = normals;
            normalsSize = length;
            normals = nullptr;
        }

        /**
         * Sets the order of the vertices stored in the object.
         * @param orderOfVertices Vec3 array of the order of the vertices.
         *      Vec3 consists of indices of the vertices from the original array.
         * @param length Integer of the length of the array.
         */
        void setOrderOfVertices(glm::ivec3 orderOfVertices[], int length) {
            delete[] Mesh::orderOfVertices;
            Mesh::orderOfVertices = orderOfVertices;
            orderOfVerticesSize = length;
            orderOfVertices = nullptr;
        }

        int getVerticesSize() {
            return verticesSize;
        }

        int getNormalsSize() {
            return normalsSize;
        }

        int getOrderSize() {
            return orderOfVerticesSize;
        }

        /**
         * Returns an array of vertices.
         * @tparam N Integer of the array. Gotten by using associated getSize function.
         * @return std::array of vertices.
         */
        template<int N>
        std::array<glm::vec3, N> getVertices(){
            return vertices;
        }

        /**
         * Returns an array of normals.
         * @tparam N Integer of the array. Gotten by using associated getSize function.
         * @return std::array of normals.
         */
        template<int N>
        std::array<glm::vec3, N> getNormals(){
            return normals;
        }

        /**
         * Returns an array of order of vertices.
         * @tparam N Integer of the array. Gotten by using associated getSize function.
         * @return std::array of the order of vertices.
         */
        template<int N>
        std::array<glm::ivec3, N> getOrder(){
            return orderOfVertices;
        }

        /**
         * Deletes the pointers.
         */
        ~Mesh() {
            delete[] vertices;
            delete[] normals;
            delete[] orderOfVertices;
        }

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
        Shader(const char* vertexPath, const char* fragmentPath){
            std::string vertexCode;
            std::string fragmentCode;
            std::ifstream vShaderFile;
            std::ifstream fShaderFile;

            //ensure ifstream objects can throw exceptions:
            vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
            fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
            try{
                //open files
                vShaderFile.open(vertexPath);
                fShaderFile.open(fragmentPath);
                std::stringstream vShaderStream, fShaderStream;
                //read file's buffer contents into streams
                vShaderStream << vShaderFile.rdbuf();
                fShaderStream << fShaderFile.rdbuf();
                //close file handlers
                vShaderFile.close();
                fShaderFile.close();
                //convert stream into string
                vertexCode = vShaderStream.str();
                fragmentCode = fShaderStream.str();
            }
            catch(std::ifstream::failure e){
                std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
            }
            const char* vShaderCode = vertexCode.c_str();
            const char* fShaderCode = fragmentCode.c_str();

            //compile shaders
            unsigned int vertex, fragment;
            //vertex
            vertex = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertex, 1, &vShaderCode, nullptr);
            glCompileShader(vertex);
            checkCompileErrors(vertex, "VERTEX");
            //fragment
            fragment = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragment, 1, &fShaderCode, nullptr);
            glCompileShader(fragment);
            checkCompileErrors(fragment, "FRAGMENT");
            //shader program
            ID = glCreateProgram();
            glAttachShader(ID, vertex);
            glAttachShader(ID, fragment);
            glLinkProgram(ID);
            checkCompileErrors(ID, "PROGRAM");
            //delete everything
            glDeleteShader(vertex);
            glDeleteShader(fragment);
        }
        ~Shader(){
            glDeleteProgram(ID);
        }
        //activate shader
        void use(){
            glUseProgram(ID);
        }

        void setBool(const std::string &name, bool value) const{
            glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
        }
        void setInt(const std::string &name, int value) const{
            glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
        }
        void setFloat(const std::string &name, float value) const{
            glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
        }
        void setVec2(const std::string &name, const glm::vec2 &value) const{
            glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
        }
        void setVec2(const std::string &name, float x, float y) const{
            glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
        }
        void setVec3(const std::string &name, const glm::vec3 &value) const{
            glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
        }
        void setVec3(const std::string &name, float x, float y, float z) const{
            glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
        }
        void setVec4(const std::string &name, const glm::vec4 &value) const{
            glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
        }
        void setVec4(const std::string &name, float x, float y, float z, float w) const{
            glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
        }
        void setMat2(const std::string &name, const glm::mat2 &mat) const{
            glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
        }
        void setMat3(const std::string &name, const glm::mat3 &mat) const{
            glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
        }
        void setMat4(const std::string &name, const glm::mat4 &mat) const{
            glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
        }

    private:
        void checkCompileErrors(unsigned int shader, std::string type){
            int success;
            char infoLog[1024];
            if(type != "PROGRAM"){
                glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
                if(!success){
                    glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
                    std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
                }
            }else{
                glGetProgramiv(shader, GL_LINK_STATUS, &success);
                if(!success){
                    glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
                    std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
                }
            }
        }
    };
}

#endif //CLOCKWORKENGINE_DEFAULTCOMPONENTS_H
