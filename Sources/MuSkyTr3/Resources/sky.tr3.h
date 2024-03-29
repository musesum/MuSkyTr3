sky { // visual music synth
    main { // main controls
        fps (1…60=60) // frames per second
        run (1) // currently running
        anim(0…1=1) // animation transition speed
    }
    network {
        bonjour // bonjour status
        follow (0…1=1) // follow remote events
        midi (0…1=1)   // follow midi events
        data << draw˚. // send draw events
    }
    pipeline { // default metal pipeline at atartup
        draw   ("draw")    // drawing layer
        ave    ("compute") // compute layer
        color  ("color")   // colorizing layer
        render ("render")  // render layer al
    }
    color { // false color mapping palette
        pal0 ("roygbik")    // palette 0: (r)ed (o)range (y)ellow …
        pal1 ("wKZ")        // palette 1: (w)hite blac(K) fractali(Z)e
        xfade (val 0…1=0.5) <~ main.anim 
    }
    input { // phone and tablet pencil input

        azimuth (x -0.2 … 0.2,
                 y -0.2 … 0.2)  >> shader.model.pipe.draw

        accel (x -0.3 … 0.3,
               y -0.3 … 0.3,
               z -0.3 … 0.3)  // accelerometer

        accel.on (0…1)

        radius (1…92=9) // finger silhouette
        tilt (0…1)        // use tilt
        force (0…0.5)     // pen pressure
        >> sky.draw.brush.size
    }
    draw { // draw on metal layer
        screen { // fill 32 bit universe
            fill(0…1=0) // all zeros 0x00000000
        }
        brush { // type of brush and range
            size (1…64=10)    // range of radius
            press (0…1=1)     // pressure changes size
            index (1…255=127) // index in 256 color palette
                              // <<(osc.tuio.z osc.manos˚z) // redirect from OSC
        }
        line { // place holder for line drawing
            prev (x 0…1, y 0…1) // staring point of segment
            next (x 0…1, y 0…1) // endint point of segment
        }
        dot (x, y, z)
    }
}
