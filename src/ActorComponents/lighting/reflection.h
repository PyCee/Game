
#ifndef _REFLECTION_
#define _REFLECTION_

typedef struct _Color_t Color_t;
typedef struct _Vector_t Normal_t;
void		PhongReflection		(Color_t *, Normal_t, Color_t, Normal_t, F32, F32, F32, F32, Color_t *, Normal_t *, U8);

#endif /* _REFLECTION_ */
