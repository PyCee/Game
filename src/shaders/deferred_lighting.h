#ifndef DEFERRED_LIGHTING
#define DEFERRED_LIGHTING

#define SHADER_DEFERRED_LIGHTING_FRAGMENT_PATH "../src/shaders/deferred_lighting.frag"

extern unsigned int deferred_lighting_buffer, deferred_lighting_texture, deferred_lighting_depth_stencil;

extern struct shader_program *deferred_lighting_shader;
extern unsigned int DLS_deferred_lighting_position_map_loc, DLS_deferred_lighting_normal_map_loc,
			DLS_deferred_lighting_color_specularity_map_loc, DLS_camera_position_loc;

void init_deferred_lighting_buffer(void);
void init_deferred_lighting_shader(void);

#endif /* DEFERRED_LIGHTING */
