shader {

    anim(0…1=0.5) << sky.main.anim ~> model.pipe.render.mirror

    model {
        cell {
            fade  (1.62…3 ) { on(0…1=0) >> cell˚on(0) << .. } <~ anim
            ave   (0…1=0.5) { on(0…1=1) >> cell˚on(0) << .. } <~ anim
            melt  (0…1=0.5) { on(0…1=0) >> cell˚on(0) << .. } <~ anim
            tunl  (0…5=1  ) { on(0…1=0) >> cell˚on(0) << .. }
            slide (0…7=3  ) { on(0…1=0) >> cell˚on(0) << .. }
            fred  (0…4=4  ) { on(0…1=0) >> cell˚on(0) << .. }
            zha   (0…6=2  ) { on(0…1=0) >> cell˚on(0) << .. bits(2…4=3) loops(11)  }
        }
        pipe {
            draw (x 0…1=0.5, y 0…1=0.5) { on(0…1=1) }
            record { on(0…1=0) }
            camera { on(0…1=0) flip (0) }
            camix  { on(0…1=0) mix(val 0…1=0.5) <~ anim }
            color  (val 0…1=0.1) <~ anim // bitplane
            render {
                frame  (x 0, y 0, w 1080, h 1920)
                repeat (x -1…1=0, y -1…1=0) <~ anim
                mirror (x 0…1, y 0…1) 
            }
        }
    }
    file {
        cell {
            fade  ("cell.fader.metal")
            ave   ("cell.ave.metal"  )
            melt  ("cell.melt.metal" )
            tunl  ("cell.tunl.metal" )
            slide ("cell.slide.metal")
            fred  ("cell.fred.metal" )
            zha   ("cell.zha.metal"  )
        }
        pipe {
            record
            camera ("cell.camera.metal")
            camix  ("cell.camix.metal" )
            draw   ("pipe.draw.metal" )
            render ("pipe.render.metal")
            color  ("pipe.color.metal" )
        }
    }
}
`
