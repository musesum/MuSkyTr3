import Foundation

public struct MuSkyTr3 {

    public static let bundle = Bundle.module

    public static func read(_ filename: String,
                            _ ext: String) -> String? {

        guard let path = Bundle.module.path(forResource: filename, ofType: ext)  else {
            print("🚫 MuSkyTr3 couldn't find file: \(filename)")
            return nil
        }
        do {
            return try String(contentsOfFile: path) }
        catch {
            print("🚫 MuSkyTr3 \(#function) error:\(error) loading contents of:\(path)")
        }
        return nil
    }

}
