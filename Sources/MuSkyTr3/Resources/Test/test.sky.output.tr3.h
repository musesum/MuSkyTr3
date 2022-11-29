sky { // visual music synth
    main { // main controls
        fps(1…60=60) // frames per second
        run(1) // currently running
    }
    pipeline { // default metal pipeline at atartup
        draw("draw") // drawing layer
        ave("compute") // compute layer
        color("color") // colorizing layer
        render("render") // render layer al
    }
    color { // false color mapping palette
        pal0("roygbik") // palette 0: (r)ed (o)range (y)ellow …
        pal1("wKZ") // palette 1: (w)hite blac(K) fractali(Z)e
        xfade(val 0…1=0.5)
    }
    input { // phone and tablet pencil input
        azimuth(x -0.2…0.2, y -0.2…0.2)>>shader.model.pipe.draw
        accel(x -0.3…0.3, y -0.3…0.3, z -0.3…0.3) { // accelerometer
            on(0…1)
        }
        radius(1…92=9) // finger silhouette
        tilt(0…1) // use tilt
        force(0…0.5)>>sky.draw.brush.size // pen pressure
    }
    draw { // draw on metal layer
        screen { // fill 32 bit universe
            fill(0) // all zeros 0x00000000
        }
        brush { // type of brush and range
            size(1…64=10) // range of radius
            press(0…1=1) // pressure changes size
            index(1…255=127) // index in 256 color palette
                             // <<(osc.tuio.z osc.manos˚z) // redirect from OSC
        }
        line { // place holder for line drawing
            prev(x 0…1, y 0…1) // staring point of segment
            next(x 0…1, y 0…1) // endint point of segment
        }
        dot(x, y, z)
    }
}
menu {
    SW {
        view {
            canvas(symbol "photo.artframe") {
                tile(image "icon.shader.tile.png") {
                    mirror(symbol "arrowtriangle.left.and.line.vertical.and.arrowtriangle.right")
                    repeat(symbol "rectangle.grid.2x2")
                    shift(image "icon.cell.scroll")
                    tilt(image "icon.pen.tilt")
                }
                color(image "icon.pal.main") {
                    fade(symbol "slider.horizontal.below.rectangle")
                    plane(symbol "square.3.layers.3d.down.right")
                    zero(symbol "drop")
                    one(symbol "drop.fill")
                }
                speed(image "icon.speed") {
                    fps(symbol "speedometer")
                    run(symbol "goforward")
                }
            }
            brush(symbol "paintbrush.pointed") {
                size(symbol "circle.circle")
                press(image "icon.pen.press")
                tilt(image "icon.pen.tilt") //(symbol "angle")
            }
            cell(symbol "circle.grid.3x3") {
                fade(image "icon.cell.fade")
                ave(image "icon.cell.ave")
                melt(image "icon.cell.melt")
                tunl(image "icon.cell.tunl")
                zha(image "icon.cell.zha")
                slide(image "icon.cell.slide")
                fred(image "icon.cell.fred")
            }
            cam(symbol "camera") {
                snap(symbol "camera.shutter.button")
                fake(symbol "face.dashed")
                real(symbol "face.smiling")
                face(symbol "arrow.triangle.2.circlepath.camera")
                mix(symbol "slider.horizontal.below.rectangle")
            }
        }
        model {
            canvas {
                tile {
                    mirror(x 0…1=0, y 0…1=0)<>shader.model.pipe.render.mirror
                    repeat(x -1…1=0, y -1…1=0)<>shader.model.pipe.render.repeat
                    shift(x 0…1=0.5, y 0…1=0.5)<>shader.model.pipe.draw
                    tilt(tog 0…1=0)<>sky.input.tilt
                }
                color {
                    fade(val 0…1=0)<>sky.color.xfade
                    plane(val 0…1=0)<>shader.model.pipe.color
                    zero(tap 0…1=0)>>sky.draw.screen.fill(0)
                    one(tap 0…1=0)>>sky.draw.screen.fill(1)
                }
                speed {
                    fps(seg 0…60=60)<>sky.main.fps
                    run(tog 0…1=1)<>sky.main.run
                }
            }
            brush {
                size(val 0…1=0.5)<>(sky.draw.brush.size, menu.SW.model.brush.press(0))
                press(tog 0…1=1)<>sky.draw.brush.press
                tilt(tog 0…1=1)<>sky.input.tilt
            }
            cell {
                fade(val 2…3=2.2)>>shader.model.cell.fade
                ave(val 0…1=0.5)>>shader.model.cell.ave
                melt(val 0…1=0.5)>>shader.model.cell.melt
                tunl(seg 0…5=1)>>shader.model.cell.tunl
                zha(seg 0…6=2)>>shader.model.cell.zha
                slide(seg 0…7=3)>>shader.model.cell.slide
                fred(seg 0…4=4)>>shader.model.cell.fred
            }
            cam {
                snap(tap 0…1=0)
                fake(tog 0…1=0)<>shader.model.pipe.camix.on
                real(tog 0…1=1)<>shader.model.pipe.camera.on
                face(tog 0…1=1)<>shader.model.pipe.camera.flip
                mix(val 0…1=0.5)<>shader.model.pipe.camix.mix
            }
        }
    }
    SE { // copy southwest corner to southeast corner
        view {
            canvas(symbol "photo.artframe") {
                tile(image "icon.shader.tile.png") {
                    mirror(symbol "arrowtriangle.left.and.line.vertical.and.arrowtriangle.right")
                    repeat(symbol "rectangle.grid.2x2")
                    shift(image "icon.cell.scroll")
                    tilt(image "icon.pen.tilt")
                }
                color(image "icon.pal.main") {
                    fade(symbol "slider.horizontal.below.rectangle")
                    plane(symbol "square.3.layers.3d.down.right")
                    zero(symbol "drop")
                    one(symbol "drop.fill")
                }
                speed(image "icon.speed") {
                    fps(symbol "speedometer")
                    run(symbol "goforward")
                }
            }
            brush(symbol "paintbrush.pointed") {
                size(symbol "circle.circle")
                press(image "icon.pen.press")
                tilt(image "icon.pen.tilt") //(symbol "angle")
            }
            cell(symbol "circle.grid.3x3") {
                fade(image "icon.cell.fade")
                ave(image "icon.cell.ave")
                melt(image "icon.cell.melt")
                tunl(image "icon.cell.tunl")
                zha(image "icon.cell.zha")
                slide(image "icon.cell.slide")
                fred(image "icon.cell.fred")
            }
            cam(symbol "camera") {
                snap(symbol "camera.shutter.button")
                fake(symbol "face.dashed")
                real(symbol "face.smiling")
                face(symbol "arrow.triangle.2.circlepath.camera")
                mix(symbol "slider.horizontal.below.rectangle")
            }
        }
        model {
            canvas {
                tile {
                    mirror(x 0…1=0, y 0…1=0)<>shader.model.pipe.render.mirror
                    repeat(x -1…1=0, y -1…1=0)<>shader.model.pipe.render.repeat
                    shift(x 0…1=0.5, y 0…1=0.5)<>shader.model.pipe.draw
                    tilt(tog 0…1=0)<>sky.input.tilt
                }
                color {
                    fade(val 0…1=0)<>sky.color.xfade
                    plane(val 0…1=0)<>shader.model.pipe.color
                    zero(tap 0…1=0)>>sky.draw.screen.fill(0)
                    one(tap 0…1=0)>>sky.draw.screen.fill(1)
                }
                speed {
                    fps(seg 0…60=60)<>sky.main.fps
                    run(tog 0…1=1)<>sky.main.run
                }
            }
            brush {
                size(val 0…1=0.5)<>(sky.draw.brush.size, menu.SE.model.brush.press(0))
                press(tog 0…1=1)<>sky.draw.brush.press
                tilt(tog 0…1=1)<>sky.input.tilt
            }
            cell {
                fade(val 2…3=2.2)>>shader.model.cell.fade
                ave(val 0…1=0.5)>>shader.model.cell.ave
                melt(val 0…1=0.5)>>shader.model.cell.melt
                tunl(seg 0…5=1)>>shader.model.cell.tunl
                zha(seg 0…6=2)>>shader.model.cell.zha
                slide(seg 0…7=3)>>shader.model.cell.slide
                fred(seg 0…4=4)>>shader.model.cell.fred
            }
            cam {
                snap(tap 0…1=0)
                fake(tog 0…1=0)<>shader.model.pipe.camix.on
                real(tog 0…1=1)<>shader.model.pipe.camera.on
                face(tog 0…1=1)<>shader.model.pipe.camera.flip
                mix(val 0…1=0.5)<>shader.model.pipe.camix.mix
            }
        }
    }
}
shader {
    model {
        cell {
            fade(0…1=0.5) {
                on(0…1=0)>>(shader.model.cell.fade.on(0), shader.model.cell.ave.on(0), shader.model.cell.melt.on(0), shader.model.cell.tunl.on(0), shader.model.cell.slide.on(0), shader.model.cell.fred.on(0), shader.model.cell.zha.on(0))<<shader.model.cell.fade
            }
            ave(0…1=0.5) {
                on(0…1=1)>>(shader.model.cell.fade.on(0), shader.model.cell.ave.on(0), shader.model.cell.melt.on(0), shader.model.cell.tunl.on(0), shader.model.cell.slide.on(0), shader.model.cell.fred.on(0), shader.model.cell.zha.on(0))<<shader.model.cell.ave
            }
            melt(0…1=0.5) {
                on(0…1=0)>>(shader.model.cell.fade.on(0), shader.model.cell.ave.on(0), shader.model.cell.melt.on(0), shader.model.cell.tunl.on(0), shader.model.cell.slide.on(0), shader.model.cell.fred.on(0), shader.model.cell.zha.on(0))<<shader.model.cell.melt
            }
            tunl(0…5=1) {
                on(0…1=0)>>(shader.model.cell.fade.on(0), shader.model.cell.ave.on(0), shader.model.cell.melt.on(0), shader.model.cell.tunl.on(0), shader.model.cell.slide.on(0), shader.model.cell.fred.on(0), shader.model.cell.zha.on(0))<<shader.model.cell.tunl
            }
            slide(0…7=3) {
                on(0…1=0)>>(shader.model.cell.fade.on(0), shader.model.cell.ave.on(0), shader.model.cell.melt.on(0), shader.model.cell.tunl.on(0), shader.model.cell.slide.on(0), shader.model.cell.fred.on(0), shader.model.cell.zha.on(0))<<shader.model.cell.slide
            }
            fred(0…4=4) {
                on(0…1=0)>>(shader.model.cell.fade.on(0), shader.model.cell.ave.on(0), shader.model.cell.melt.on(0), shader.model.cell.tunl.on(0), shader.model.cell.slide.on(0), shader.model.cell.fred.on(0), shader.model.cell.zha.on(0))<<shader.model.cell.fred
            }
            zha(0…6=2) {
                on(0…1=0)>>(shader.model.cell.fade.on(0), shader.model.cell.ave.on(0), shader.model.cell.melt.on(0), shader.model.cell.tunl.on(0), shader.model.cell.slide.on(0), shader.model.cell.fred.on(0), shader.model.cell.zha.on(0))<<shader.model.cell.zha
                bits(2…4=3)
                loops(11)
            }
        }
        pipe {
            draw(x 0…1=0.5, y 0…1=0.5) {
                on(0…1=0)
            }
            record {
                on(0…1=0)
            }
            camera {
                on(0…1=0)
                flip(tog 0)
            }
            camix {
                on(0…1=0)
                mix(val 0…1=0.5)
            }
            color(val 0…1=0.1) // bitplane
            render {
                frame(x 0, y 0, w 1080, h 1920)
                repeat(x -1…1=0, y -1…1=0)
                mirror(x 0…1, y 0…1)
            }
        }
    }
    file {
        cell {
            fade("cell.fader.metal")
            ave("cell.ave.metal")
            melt("cell.melt.metal")
            tunl("cell.tunl.metal")
            slide("cell.slide.metal")
            fred("cell.fred.metal")
            zha("cell.zha.metal")
        }
        pipe {
            record camera("cell.camera.metal")
            camix("cell.camix.metal")
            draw("pipe.draw.metal")
            render("pipe.render.metal")
            color("pipe.color.metal")
        }
    }
}
