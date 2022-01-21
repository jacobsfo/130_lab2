#include "render_world.h"
#include "flat_shader.h"
#include "object.h"
#include "light.h"
#include "ray.h"
#include <vector>
using namespace std;
extern bool disable_hierarchy;

Render_World::Render_World()
    :background_shader(0),ambient_intensity(0),enable_shadows(true),
    recursion_depth_limit(3)
{}

Render_World::~Render_World()
{
    delete background_shader;
    for(size_t i=0;i<objects.size();i++) delete objects[i];
    for(size_t i=0;i<lights.size();i++) delete lights[i];
}

// Find and return the Hit structure for the closest intersection.  Be careful
// to ensure that hit.dist>=small_t.
Hit Render_World::Closest_Intersection(const Ray& ray)
{
    TODO;
    Hit min_t;
   min_t = std::numeric_limits<Hit>::max();
    Hit a; 
  //  Hit b;
//    b = a.object->Intersection(ray,a.part);
vector<Hit>c;
//if(b 
for(int i = 0; i < c.size();i++)
{   c[i].object->Intersection(ray,c[i].part);
  
if(c[i].dist <= 0 && c[i].dist > small_t)
   {
    min_t.dist = c[i].dist;
   }
}
 return min_t;
}

// set up the initial view ray and call
void Render_World::Render_Pixel(const ivec2& pixel_index)
{
    TODO; // set up the initial view ray here
    Ray ray;
    ray.direction = ray.direction.normalized();
    ray.Point(0.0);  
   // ray(endpoint,direction);
    vec3 color=Cast_Ray(ray,1);
    camera.Set_Pixel(pixel_index,Pixel_Color(color));
}

void Render_World::Render()
{
    if(!disable_hierarchy)
        Initialize_Hierarchy();

    for(int j=0;j<camera.number_pixels[1];j++)
        for(int i=0;i<camera.number_pixels[0];i++)
            Render_Pixel(ivec2(i,j));
}

// cast ray and return the color of the closest intersected surface point,
// or the background color if there is no object intersection
vec3 Render_World::Cast_Ray(const Ray& ray,int recursion_depth)
{
    vec3 color;
  //  Object o;
//    Flat_Shader p;
    TODO; // determine the color here
    //if ray hits object
/* 
   if(Closest_intersection(ray)!=NULL)
     {
      color = 
     }
     
    //set color to intersection
 //   color = Closest_intersection(ray); 
    //else
    //set color to background color
   // color = p.Shade_Surface(ray,
     else
     {
     color = 
     } 
*/
   return color;
}

void Render_World::Initialize_Hierarchy()
{
    TODO; // Fill in hierarchy.entries; there should be one entry for
    // each part of each object.
    //extra credit
    hierarchy.Reorder_Entries();
    hierarchy.Build_Tree();
}
