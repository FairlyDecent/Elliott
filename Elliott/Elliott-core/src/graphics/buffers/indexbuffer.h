#pragma once

#include <GL\glew.h>

namespace elliott { namespace graphics {

	class IndexBuffer
	{
	private:
		GLuint m_BufferID;
		GLuint m_Count;
	public:
		IndexBuffer(GLushort* data, GLsizei count, GLuint componentCount);

		void bind() const;
		void unbind() const;

		inline GLuint getCount() const { return m_Count; }
	};

} }