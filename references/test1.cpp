void VeNgoiNha(float r)
{
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_QUADS);
	// Bottom face (y = -r)
	glColor3f(1.0f, 0.5f, 0.0f);     // Orange
	glVertex3f(r, -r, r);
	glVertex3f(-r, -r, r);
	glVertex3f(-r, -r, -r);
	glVertex3f(r, -r, -r);
	
	// Front face  (z = r)
	glColor3f(r, 0.0f, 0.0f);     // Red
	glVertex3f(r, r, r);
	glVertex3f(-r, r, r);
	glVertex3f(-r, -r, r);
	glVertex3f(r, -r, r);
	
	// Back face (z = -r)
	glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
	glVertex3f(r, -r, -r);
	glVertex3f(-r, -r, -r);
	glVertex3f(-r, r, -r);
	glVertex3f(r, r, -r);
	
	// Left face (x = -r)
	glColor3f(0.0f, 0.0f, 1.0f);     // Blue
	glVertex3f(-r, r, r);
	glVertex3f(-r, r, -r);
	glVertex3f(-r, -r, -r);
	glVertex3f(-r, -r, r);
	
	// Right face (x = r)
	glColor3f(r, 0.0f, r);     // Magenta
	glVertex3f(r, r, -r);
	glVertex3f(r, r, r);
	glVertex3f(r, -r, r);
	glVertex3f(r, -r, -r);
  // End of drawing color-cube
	glEnd();
}