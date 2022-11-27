menu  {
    SW {
        view (depth 0, touch 0) {
            canvas (symbol "photo.artframe", touch 0) {
                tile (image "icon.shader.tile.png", touch 0) {
                    mirror (symbol "arrowtriangle.left.and.line.vertical.and.arrowtriangle.right", touch 0)
                    repeat (symbol "rectangle.grid.2x2" , touch 0)
                    shift (image "icon.cell.scroll", touch 0)
                    tilt  (image "icon.pen.tilt", touch 0)
                }
                color(image "icon.pal.main", touch 0) {
                    fade  (symbol "slider.horizontal.below.rectangle", touch 0)
                    plane (symbol "square.3.layers.3d.down.right", touch 0)
                    zero  (symbol "drop", touch 0)
                    one   (symbol "drop.fill", touch 0)
                }
                speed (image "icon.speed", touch 0) {
                    fps (symbol "speedometer", touch 0)
                    run (symbol "goforward", touch 0)
                }
            }
            brush (symbol "paintbrush.pointed", touch 0) {
                size  (symbol "circle.circle", touch 0)
                press (image "icon.pen.press", touch 0)
                tilt  (image "icon.pen.tilt", touch 0)  //(symbol "angle", touch 0)
            }
            cell (symbol "circle.grid.3x3", touch 0) {
                fade  (image "icon.cell.fade" , touch 0)
                ave   (image "icon.cell.ave"  , touch 0)
                melt  (image "icon.cell.melt" , touch 0)
                tunl  (image "icon.cell.tunl" , touch 0)
                zha   (image "icon.cell.zha"  , touch 0)
                slide (image "icon.cell.slide", touch 0)
                fred  (image "icon.cell.fred" , touch 0)
            }
            cam (symbol "camera", touch 0) {
                snap  (symbol "camera.shutter.button", touch 0)
                fake  (symbol "face.dashed", touch 0)
                real  (symbol "face.smiling", touch 0)
                face  (symbol "arrow.triangle.2.circlepath.camera", touch 0)
                mix   (symbol "slider.horizontal.below.rectangle", touch 0)
            }
        }
        model {
            canvas {
                tile  {
                    mirror (x 0…1=0,
                            y 0…1=0) >> shader.model.pipe.render.mirror

                    repeat (x -1…1=0.5,
                            y -1…1=0.5) >> shader.model.pipe.render.repeat

                    shift (x 0…1=0.5,
                           y 0…1=0.5) <> shader.model.pipe.draw

                    tilt  (tog 0…1=0) <> sky.input.tilt
                }
                color {
                    fade  (val 0…1=0) <> sky.color.xfade
                    plane (val 0…1=0) <> shader.model.pipe.color
                    zero  (tap 0…1=0) >> sky.draw.screen.fill(0)
                    one   (tap 0…1=0) >> sky.draw.screen.fill(1)
                }
                speed {
                    fps (seg 0…60=60) >> sky.main.fps
                    run (tog 0…1 =1 ) >> sky.main.run
                }
            }
            brush {
                size  (val 0…1=0.5) >> (sky.draw.brush.size, press(0))
                press (tog 0…1=1  ) >> sky.draw.brush.press
                tilt  (tog 0…1=1  ) <> sky.input.tilt
            }
            cell {
                fade  (val 2…3=2.2) >> shader.model.cell.fade
                ave   (val 0…1=0.5) >> shader.model.cell.ave
                melt  (val 0…1=0.5) >> shader.model.cell.melt
                tunl  (seg 0…5=1  ) >> shader.model.cell.tunl
                zha   (seg 0…6=2  ) >> shader.model.cell.zha
                slide (seg 0…7=3  ) >> shader.model.cell.slide
                fred  (seg 0…4=4  ) >> shader.model.cell.fred
            }
            cam {
                snap  (tap 0…1=0  )
                fake  (tog 0…1=0  ) >> shader.model.pipe.camix.on
                real  (tog 0…1=1  ) >> shader.model.pipe.camera.on
                face  (tog 0…1=1  ) >> shader.model.pipe.camera.flip
                mix   (val 0…1=0.5) >> shader.model.pipe.camix.mix
            }
        }
    }
    SE @ SW // copy southwest corner
}
