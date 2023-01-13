#include "auxiliar.h"
#include "textura.h"

// *****************************************************************************
//
// IG_D Clase textura
//
// *****************************************************************************
// -----------------------------------------------------------------------------

Textura::Textura(std::string archivo)
{
    pimg = new jpg::Imagen(archivo);
    width = pimg -> tamX(); // núm. columnas (unsigned)
    height = pimg -> tamY(); // núm. filas (unsigned)
    // std::cout << width << " width"<< std::endl;
    // std::cout << height << " height"<< std::endl;
    // texels = pimg -> leerPixels(); // puntero texels (unsigned char *)
    // for (unsigned int i = 0; i<width*height*3; i++){
    //         data.push_back(texels[i]);
    // }
    // std::cout << "DATA SIZE IS "<< data.size() << std::endl;
    for(int i = height-1; i >= 0; i--){     // recorre filas de la imagen de ultima a primera
        for(int j = 0; j < width; j++)      // recorre columnas de la imagen de primera a ultima
        {
            texels = pimg->leerPixel(j,i);  // devuelve puntero a w*j_fila + i_columna
            data.push_back(*texels);
            data.push_back(*(texels+1));
            data.push_back(*(texels+2));
        }
    }
}


void Textura::activar()
{
    // glEnable(GL_TEXTURE_2D);
    // if (idTex == 0)
    //     glGenTextures( 1 , &idTex ); // idTex almacena el nuevo identificador
    // std::cout << "Valor idText "<< idTex << std::endl;
    // glBindTexture( GL_TEXTURE_2D, idTex );
    // glTexImage2D ( GL_TEXTURE_2D ,
    //                             0 , // nivel de mipmap (para imágenes multiresolución)
    //                             GL_RGB , // formato interno
    //                             width , // núm. de columnas (potencia de dos: 2n)
    //                             height , // núm de filas (potencia de dos: 2m)
    //                             0 , // tamaño del borde, usualmente es 0
    //                             GL_RGB , // formato y orden de los texels en RAM
    //                             GL_UNSIGNED_BYTE , // tipo de cada texel
    //                             &data[0] // puntero a los bytes con texels (void *)
    //                 );
    
    glEnable( GL_TEXTURE_2D );
    
    if(nuevo){
        // generamos el identificador de textura
        glGenTextures(1, &idTex);
        // transferimos los texels a la gpu
        glBindTexture(GL_TEXTURE_2D,idTex);
        //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, &data[0]);
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, &data[0]);
        //glBindTexture(GL_TEXTURE_2D,0);
        nuevo = false;
    }else{
        glBindTexture( GL_TEXTURE_2D, idTex ); // activa el id de textura del objeto que llama a la funcion
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);
    }
}

