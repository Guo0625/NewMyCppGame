
#ifdef GL_ES
precision mediump float;
#endif

varying vec2 v_texCoord;
uniform vec4 u_grayParam;

void main(void) {
    vec4 texColor = texture2D(CC_Texture0, v_texCoord);
    texColor = texColor*u_grayParam;
    gl_FragColor = texColor;
}
