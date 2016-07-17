#ifndef GEOMETRY
#define GEOMETRY

#define SHADER_GEOMETRY_VERTEX_PATH "../src/shaders/geometry.vert"
#define SHADER_GEOMETRY_FRAGMENT_PATH "../src/shaders/geometry.frag"

//TODO store only the position's z value in a map insted of xyz
extern unsigned int geometry_buffer, geometry_buffer_position_map,
		geometry_buffer_normal_map, geometry_buffer_color_specularity_map, geometry_buffer_depth_stencil;

extern struct shader_program *geometry_shader;
extern unsigned int GS_world_space_loc, GS_view_space_loc, GS_clip_space_loc, GS_texture_map_loc;

void init_geometry_buffer(void);
void init_geometry_shader(void);

#endif /* GEOMETRY */
