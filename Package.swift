// swift-tools-version: 5.7

import PackageDescription

let package = Package(
    name: "MuSkyTr3",
    products: [
        .library(
            name: "MuSkyTr3",
            targets: ["MuSkyTr3"]),
    ],
    dependencies: [
    ],
    targets: [
        .target(
            name: "MuSkyTr3",
            dependencies: [],
            resources: [.process("Resources")]),
        .testTarget(
            name: "MuSkyTr3Tests",
            dependencies: ["MuSkyTr3"]),
    ]
)
