#ifndef BUFFER_PLANE
#define BUFFER_PLANE

#define SHADER_BUFFER_PLANE_VERTEX_PATH "../src/shaders/buffer_plane.vert"
#define SHADER_BUFFER_PLANE_FRAGMENT_PATH "../src/shaders/buffer_plane.frag"

extern struct shader_program *buffer_plane_shader;
extern unsigned int BPS_texture_loc;

extern unsigned int buffer_plane_vao, buffer_plane_vbo, buffer_plane_ebo;

void init_buffer_plane_buffers(void);
void init_buffer_plane_shaders(void);
void draw_buffer_plane(void);

#endif /* BUFFER_PLANE */
