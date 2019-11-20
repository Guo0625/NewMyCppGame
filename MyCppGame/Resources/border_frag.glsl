precision mediump float;

varying vec2 v_texCoord;
varying float scroll_speed;

uniform float u_borderLength;
uniform int u_isFlipped;
uniform float u_posOffset;
uniform int u_texIdx;
uniform int u_borderIdx;

void main() {
    float boundaryNoneFactor = 0.93;
    float boundaryNone = (1.0 - u_borderLength * boundaryNoneFactor) * 0.5;
    if ((v_texCoord.y < boundaryNone) || (v_texCoord.y > 1.0 - boundaryNone))
        gl_FragColor = vec4(10, 10, 10, 10);
    else {
        vec2 texCoord;
        if (u_isFlipped == 1)
            texCoord = vec2(v_texCoord.x + 0.2 * float(u_borderIdx),
                            u_posOffset + (1.0 - v_texCoord.y) * u_borderLength * boundaryNoneFactor);
        else
            texCoord = vec2(v_texCoord.x + 0.2 * float(u_borderIdx),
                            u_posOffset + v_texCoord.y * u_borderLength * boundaryNoneFactor);
        
        float boundaryFadeFactor = 0.85;
        float boundaryFade = (1.0 - u_borderLength * boundaryFadeFactor) * 0.5;
        float texAlphaModifier;
        if (v_texCoord.y < boundaryFade)
            texAlphaModifier = (v_texCoord.y - boundaryNoneFactor) / (boundaryNoneFactor - boundaryFadeFactor);
        else if (v_texCoord.y > 1.0 - boundaryFade)
            texAlphaModifier = (1.0 - boundaryNoneFactor - v_texCoord.y) / (boundaryNoneFactor - boundaryFadeFactor);
        else
            texAlphaModifier = 1.0;
        
        vec4 texBorder;
        if (u_texIdx == 1)
            texBorder = texture2D(CC_Texture1, texCoord);
        else if (u_texIdx == 2)
            texBorder = texture2D(CC_Texture2, texCoord);
        else if (u_texIdx == 3)
            texBorder = texture2D(CC_Texture3, texCoord);
        
        gl_FragColor = vec4(texBorder.rgb, texBorder.a * texAlphaModifier * pow((1.0 - v_texCoord.x), 8.0));
    }
}
