menu  {
    model {
        canvas {
            tile  {
                mirror (x 0…1=0,
                        y 0…1=0) <> shader.model.pipe.render.mirror

                repeat (x -1…1=0,
                        y -1…1=0) <> shader.model.pipe.render.repeat

                shift (x 0…1=0.5,
                       y 0…1=0.5) <> shader.model.pipe.draw

                tilt  (tog 0…1=0) <> sky.input.tilt
            }
            color {
                fade  (val 0…1=0) <> sky.color.xfade
                plane (val 0…1=0) <> shader.model.pipe.color
                fill  (seg 0…1=0) >> sky.draw.screen.fill
            }
            speed {
                fps (seg 0…60=60) <> sky.main.fps
                run (seg 0…1=1 ) <> sky.main.run
                anim(val 0…1=0.24) <> sky.main.anim
            }
        }
        brush {
            size  (val 0…1=0.5) <> sky.draw.brush.size
            press (tog 0…1=1  ) >> sky.draw.brush.press
            tilt  (tog 0…1=1  ) <> sky.input.tilt
        }
        cell {
            fade  (val 2…3=2.2) <> shader.model.cell.fade
            ave   (val 0…1=0.5) <> shader.model.cell.ave
            melt  (val 0…1=0.5) <> shader.model.cell.melt
            tunl  (seg 0…5=1  ) <> shader.model.cell.tunl
            zha   (seg 0…6=2  ) <> shader.model.cell.zha
            slide (seg 0…7=3  ) <> shader.model.cell.slide
            fred  (seg 0…4=4  ) <> shader.model.cell.fred
        }
        cam {
            snap  (tap 0…1=0  )
            fake  (tog 0…1=0  ) <> shader.model.pipe.camix.on
            real  (tog 0…1=1  ) <> shader.model.pipe.camera.on
            face  (tog 0…1=1  ) <> shader.model.pipe.camera.flip
            mix   (val 0…1=0.5) <> shader.model.pipe.camix.mix
        }
        network (symbol "network") {
            bonjour (peer "bonjour") <> sky.main.peer.bonjour
            follow  (tog 0…1=1) <> sky.main.peer.follow
            midi    (tog 0…1=1) <> sky.main.peer.midi
        }
    }
    SW {
        view {
            canvas (symbol "photo.artframe") {
                tile (image "icon.shader.tile.png") {
                    mirror (symbol "arrowtriangle.left.and.line.vertical.and.arrowtriangle.right")
                    repeat (symbol "rectangle.grid.2x2" )
                    shift (image "icon.cell.scroll")
                    tilt  (symbol "angle")
                }
                color(image "icon.pal.main") {
                    fade  (symbol "slider.horizontal.below.rectangle")
                    plane (symbol "square.3.layers.3d.down.right")
                    fill  (symbol "drop.fill")
                }
                speed (image "icon.speed") {
                    fps (symbol "speedometer")
                    run (symbol "goforward")
                    anim (symbol "bolt.fill")
                }
            }
            brush (symbol "paintbrush.pointed") {
                size  (symbol "circle.circle")
                press (symbol "scribble.variable")
                tilt  (symbol "angle")  //(symbol "angle")
            }
            cell (symbol "circle.grid.3x3") {
                fade  (image "icon.cell.fade" )
                ave   (image "icon.cell.ave"  )
                melt  (image "icon.cell.melt" )
                tunl  (image "icon.cell.tunl" )
                zha   (image "icon.cell.zha"  )
                slide (image "icon.cell.slide")
                fred  (image "icon.cell.fred" )
            }
            cam (symbol "camera") {
                snap  (symbol "camera.shutter.button")
                fake  (symbol "face.dashed")
                real  (symbol "face.smiling")
                face  (symbol "arrow.triangle.2.circlepath.camera")
                mix   (symbol "camera.filters")
            }
            network (symbol "network") {
                bonjour (symbol "bonjour")
                follow (symbol "shared.with.you")
                midi (symbol "pianokeys.inverse")
            }
        }
    }
    SE @ SW // copy southwest to other corners
    NE @ SW
    NW @ SW
}
