#include "obiekty.h"
#include "consola.h"
#include "tekstury.h"
#include "elementy.h"
#include <SFML/Graphics.hpp>
#include "okna.h"

using namespace sf;
ele *elementy;


ele::ele():narzedzia(Vector2f(1920,200))
{

}

ele::~ele()
{
}