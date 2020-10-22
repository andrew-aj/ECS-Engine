//
// Created by Andrew Knee on 10/17/2020.
//

#ifndef CLOCKWORKENGINE_DEFAULTCOMPONENTS_H
#define CLOCKWORKENGINE_DEFAULTCOMPONENTS_H

#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/glm.hpp>
#include <array>

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

    private:
        glm::vec3 position;
        glm::quat quatRotation;
        glm::vec3 scale;
    };


    /**
     * Stores all relevant physics information of 3D rigidbody.
     * Used in conjunction with transform for which the variables in here are set in the transform.
     */
    struct RigidBody {
        glm::vec3 velocity;
        glm::vec3 position;
        glm::quat rotation;
        glm::vec3 angularVelocity;

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
    };

    /**
     * Contains the mesh data.
     * Stores the Vec3 of vertices, normals, and the pairing of vertices to create polygons.
     */
    struct Mesh {
        int verticesSize = 0, normalsSize = 0, orderOfVerticesSize = 0;
        glm::vec3 *vertices;
        glm::vec3 *normals;
        glm::vec3 *orderOfVertices;

        /**
         * Sets the vertices stored in the object.
         * @param vertices Vec3 array of the vertex vectors.
         * @param length Integer of the length of the array.
         */
        void setVertices(glm::vec3 vertices[], int length) {
            delete[] vertices;
            Mesh::vertices = vertices;
            verticesSize = length;
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
        }

        /**
         * Sets the order of the vertices stored in the object.
         * @param orderOfVertices Vec3 array of the order of the vertices.
         *      Vec3 consists of indices of the vertices from the original array.
         * @param length Integer of the length of the array.
         */
        void setOrderOfVertices(glm::vec3 orderOfVertices[], int length) {
            delete[] Mesh::orderOfVertices;
            Mesh::orderOfVertices = orderOfVertices;
            orderOfVerticesSize = length;
        }

        /**
         * Returns the vertices.
         * @param vertices Vec3 pointer to store the value of the vertices.
         * @param size Integer reference to get size of the array.
         */
        void getVertices(glm::vec3 *vertices, int &size) {
            size = verticesSize;
            vertices = Mesh::vertices;
        }

        /**
         * Returns the normals.
         * @param normals Vec3 pointer to store the value of the normals.
         * @param size Integer reference to get size of the array.
         */
        void getNormals(glm::vec3 *normals, int &size) {
            size = normalsSize;
            normals = Mesh::normals;
        }

        /**
         * Returns the order of the vertices.
         * @param orderOfVertices Vec3 pointer to store the value of the order.
         * @param size Integer reference to get size of the array.
         */
        void getOrder(glm::vec3 *orderOfVertices, int &size) {
            size = orderOfVerticesSize;
            orderOfVertices = Mesh::orderOfVertices;
        }

        /**
         * Deletes the pointers.
         */
        ~Mesh() {
            delete[] vertices;
            delete[] normals;
            delete[] orderOfVertices;
        }
    };
}

#endif //CLOCKWORKENGINE_DEFAULTCOMPONENTS_H
