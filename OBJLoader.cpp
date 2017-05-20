#include "OBJLoader.h"

#include <iostream>
#include <sstream>
#include <fstream>
void MakeSlashToSpace(std::string& str)
{
	for(int i=0;i<str.size();i++)
		if(str[i]=='/')
			str[i] = ' ';
}
Object::
Object()
{

}

Object::
Object(const std::string& file_path)
{
	Load(file_path);
}


Object::
~Object()
{

}

void
Object::
Load(const std::string& file_path)
{
	std::ifstream ifs(file_path);
	if(!(ifs.is_open()))
	{
		std::cout<<"Can't read file "<<file_path<<std::endl;
		return;
	}
	std::string str;
	std::string index;
	std::stringstream ss;

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
	std::vector<glm::ivec3> faces;
	while(!ifs.eof())
	{
		str.clear();
		index.clear();
		ss.clear();

		std::getline(ifs,str);
		ss.str(str);
		std::cout<<str<<"   ";
		ss>>index;

		if(!index.compare("v"))
		{
			std::cout<<"Its v"<<std::endl;
			double x,y,z;
			ss>>x>>y>>z;
			vertices.push_back(glm::vec3(x,y,z));
		}
		else if(!index.compare("vt"))
		{
			std::cout<<"Its vt"<<std::endl;
			double u,v;
			ss>>u>>v;
			uvs.push_back(glm::vec2(u,v));
		}
		else if(!index.compare("vn"))
		{
			std::cout<<"Its vn"<<std::endl;
			double nx,ny,nz;
			ss>>nx>>ny>>nz;
			normals.push_back(glm::vec3(nx,ny,nz));
		}
		else if(!index.compare("f"))
		{
			std::cout<<"Its f"<<std::endl;
			std::string token;
			
			for(int i=0;i<3;i++)
			{
				int vi = 0,vti = 0,vni = 0;
				ss>>token;
				MakeSlashToSpace(token);
				std::stringstream ss_token(token);
				ss_token>>vi>>vti>>vni;
				faces.push_back(glm::ivec3(vi,vti,vni));
				std::cout<<vi<<" "<<vti<<" "<<vni<<std::endl;
			}
			
		}
	}
	ifs.close();

	for(int i=0;i<faces.size();i++)
	{
		m_vertices.push_back(vertices[faces[i].x-1]);
		m_uvs.push_back(uvs[faces[i].y-1]);
		m_normals.push_back(normals[faces[i].z-1]);
	}


}

void
Object::
InitializeBuffer()
{
	glGenBuffers(1,&m_vert_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_vert_buffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(glm::vec3),&m_vertices[0], GL_STATIC_DRAW);
	glGenBuffers(1,&m_uv_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_uv_buffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(glm::vec2),&m_uvs[0], GL_STATIC_DRAW);
	glGenBuffers(1,&m_normal_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_normal_buffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(glm::vec3),&m_normals[0], GL_STATIC_DRAW);

	isBufferInitialized = true;
}


void
Object::
Render()
{
	if(!isBufferInitialized)
		InitializeBuffer();

	glBindBuffer(GL_ARRAY_BUFFER, m_vert_buffer);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, sizeof(glm::vec3),(void*)(0));

	// glBindBuffer(GL_ARRAY_BUFFER, m_normals_buffer);
	// glEnableClientState(GL_NORMAL_ARRAY);
	// glVertexPointer(3, GL_FLOAT, sizeof(glm::vec3),(void*)(0));

	// glBindBuffer(GL_ARRAY_BUFFER, m_vert_buffer);
	// glEnableClientState(GL_VERTEX_ARRAY);
	// glVertexPointer(3, GL_FLOAT, sizeof(glm::vec3),(void*)(0));

	glDrawArrays(GL_TRIANGLES, 0, m_vertices.size() );
}