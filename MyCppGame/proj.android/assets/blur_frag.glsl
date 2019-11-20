
varying lowp vec4 v_fragmentColor;
varying mediump vec2 v_texCoord;

uniform vec3 u_color ;    // 描边颜色
uniform float u_line_size ;    //描边偏移大小

// 获得背面区域
float getBackArea()
{
    vec4 color_up;
    vec4 color_down;
    vec4 color_left;
    vec4 color_right;
    vec4 color_up_left;
    vec4 color_up_right;
    vec4 color_down_left;
    vec4 color_down_right;
    float total = 0.0 ;
    
    color_up = texture2D(CC_Texture0, v_texCoord + vec2(0, u_line_size));
    color_down = texture2D(CC_Texture0, v_texCoord - vec2(0, u_line_size));
    color_left = texture2D(CC_Texture0, v_texCoord - vec2(u_line_size, 0));
    color_right = texture2D(CC_Texture0, v_texCoord + vec2(u_line_size, 0));
    color_up_left = texture2D(CC_Texture0, v_texCoord + vec2(u_line_size, -u_line_size));
    color_up_right = texture2D(CC_Texture0, v_texCoord + vec2(u_line_size, u_line_size));
    color_down_left = texture2D(CC_Texture0, v_texCoord + vec2(-u_line_size, -u_line_size));
    color_down_right = texture2D(CC_Texture0, v_texCoord + vec2(-u_line_size, u_line_size));
    total = color_right.a + color_left.a + color_down.a + color_up.a +
    color_up_left.a + color_up_right.a + color_down_left.a + color_down_right.a;
    return clamp(total, 0.0, 1.0);
}

void main()
{
    // 获取正常的颜色值
    vec4 fragColor = v_fragmentColor * texture2D(CC_Texture0, v_texCoord);
    float isBack = getBackArea();
    
    // 正常的rgb + 正常的透明区域 * 背面颜色 * 描边颜色
    gl_FragColor = vec4(fragColor.rgb + (1.0 - fragColor.a)* u_color * isBack, 1.0);
}
