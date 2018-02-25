void multiply(float mat1[][4], float mat2[][4],float res[][4])
{
    int i, j, k;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < 3; k++)
                res[i][j] += mat1[i][k]*mat2[k][j];
        }
    }
}

void transform()
{
	GLfloat mat1[4][4] , trans[3][4] , res[4][4];
	mat1[0][0] = 10.0f;
	mat1[0][1] = 30.0f;
	mat1[1][0] = 40.0f;
	mat1[1][1] = 30.0f;
	mat1[2][0] = 40.0f;
	mat1[2][1] = 10.0f;
	mat1[3][0] = 10.0f;
	mat1[3][1] = 10.0f;
	for(int i = 0 ; i < 4 ; i++)
		mat1[i][2] = 1;
	glBegin(GL_QUADS);
	for(int i = 0 ; i < 4 ; i++)
		glVertex2f(mat1[i][0] , mat1[i][1]);
	glEnd();
	trans[0][0] = 20.0f;
	trans[0][1] = 0.0f;
	trans[0][2] = 0.0f;
	trans[1][0] = 0.0f;
	trans[1][1] = 20.0f;
	trans[1][2] = 0.0f;
	trans[2][0] = 0.0f;
	trans[2][1] = 0.0f;
	trans[2][2] = 1.0f;
	multiply(mat1 , trans , res);
	glBegin(GL_QUADS);
		for(int i = 0 ; i < 4 ; i++)
			glVertex2f(res[i][0] , res[i][1]);
	glEnd();
}
