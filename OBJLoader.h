#ifndef __OBJ_LOADER_H__
#define __OBJ_LOADER_H__
#include <glm/glm.hpp>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <string>
#include <vector>
class Object
{
private:
	std::vector<glm::vec3> m_vertices;
	std::vector<glm::vec2> m_uvs;
	std::vector<glm::vec3> m_normals;

	GLuint m_vert_buffer;
	GLuint m_uv_buffer;
	GLuint m_normal_buffer;

	bool isBufferInitialized = false;
public:
	Object();
	Object(const std::string& file_path);
	~Object();

	void Load(const std::string& file_path);
	void InitializeBuffer();
	void Render();
};



#endif


