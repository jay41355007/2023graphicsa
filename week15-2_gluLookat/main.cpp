#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void reshape(int w,int h)
{
    glViewport(0,0,w,h);///�����|�ݨ�2D�d��
    float ar=w / (float) h;///aspect ratuio���e��
    glMatrixMode(GL_PROJECTION);///��������Project�x�}
    glLoadIdentity();///�x�}�M�šA�������x�}(�̤@�}�l���x�})
    gluPerspective(60,ar,0.01,1000);///�@���ťաA�b������

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,1, 0,0,0, 0,1,0);
    glutPostRedisplay();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week15");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);///�Ѯv��W�r��reshape

    glutMainLoop();
}