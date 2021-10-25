#ifndef CUBE_H
#define CUBE_H
#include <SFML/OpenGL.hpp>

using namespace sf;
constexpr auto GL_CLAMP_TO_EDGE = 0x812F;

GLuint LoadTexture(String name) {

	Image image;
	image.loadFromFile(name);
	image.flipVertically();

	GLuint texture = 0;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, image.getSize().x, image.getSize().y, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	return texture;
}

void createCube(GLuint box[], float size) {
	    glBindTexture(GL_TEXTURE_2D, box[0]);
	    glBegin(GL_QUADS);
		    //front
            glTexCoord2f(0, 0);   glVertex3f(-size, -size, -size);
            glTexCoord2f(1, 0);   glVertex3f(size,  -size, -size);
            glTexCoord2f(1, 1);   glVertex3f( size,  size, -size);
            glTexCoord2f(0, 1);   glVertex3f( -size, size, -size);
        glEnd();
		
	    glBindTexture(GL_TEXTURE_2D, box[1]);
	    glBegin(GL_QUADS);
			//back
            glTexCoord2f(0, 0); glVertex3f(size, -size, size);
            glTexCoord2f(1, 0); glVertex3f(-size,  -size, size);
            glTexCoord2f(1, 1); glVertex3f( -size,  size, size);
            glTexCoord2f(0, 1); glVertex3f( size, size, size);
        glEnd();

		glBindTexture(GL_TEXTURE_2D, box[2]);
	    glBegin(GL_QUADS);
			//left
            glTexCoord2f(0, 0); glVertex3f(-size, -size,  size);
            glTexCoord2f(1, 0); glVertex3f(-size, -size, -size);
            glTexCoord2f(1, 1); glVertex3f(-size,  size, -size);
            glTexCoord2f(0, 1); glVertex3f(-size,  size,  size);
        glEnd();

		glBindTexture(GL_TEXTURE_2D, box[3]);
	    glBegin(GL_QUADS);
			//right
            glTexCoord2f(0, 0); glVertex3f(size, -size, -size);
            glTexCoord2f(1, 0); glVertex3f(size,  -size, size);
            glTexCoord2f(1, 1); glVertex3f(size,  size,  size);
            glTexCoord2f(0, 1); glVertex3f(size, size,  -size);
        glEnd();

		glBindTexture(GL_TEXTURE_2D, box[4]);
	    glBegin(GL_QUADS);
			//bottom
            glTexCoord2f(0, 0); glVertex3f(-size, -size,  size);
            glTexCoord2f(1, 0); glVertex3f(size, -size, size);
            glTexCoord2f(1, 1); glVertex3f( size, -size, -size);
            glTexCoord2f(0, 1); glVertex3f( -size, -size,  -size);
        glEnd();

	    glBindTexture(GL_TEXTURE_2D, box[5]);
	    glBegin(GL_QUADS);
			//top  		
            glTexCoord2f(0, 0); glVertex3f(-size, size,  -size);
            glTexCoord2f(1, 0); glVertex3f(size, size, -size);
            glTexCoord2f(1, 1); glVertex3f( size, size, size);
            glTexCoord2f(0, 1); glVertex3f( -size, size,  size);	     
        glEnd();
}

#endif CUBE_H