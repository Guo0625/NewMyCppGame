attribute vec4 a_position;
attribute vec2 a_texCoord;
attribute vec4 a_color;

varying highp float scroll_speed;
varying vec2 v_texCoord;

void main()
{
    gl_Position = CC_PMatrix * a_position;
    v_texCoord = a_texCoord;
    scroll_speed = fract(0.1 * CC_Time[1]);
}
