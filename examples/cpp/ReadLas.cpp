// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2018-2021 www.open3d.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#include <Eigen/Dense>
#include <iostream>
#include <memory>

#include "open3d/Open3D.h"

void PrintPointCloud(const open3d::geometry::PointCloud &pointcloud) {
    using namespace open3d;

    bool pointcloud_has_normal = pointcloud.HasNormals();
    utility::LogInfo("Pointcloud has %d points.",
                     (int)pointcloud.points_.size());

    Eigen::Vector3d min_bound = pointcloud.GetMinBound();
    Eigen::Vector3d max_bound = pointcloud.GetMaxBound();
    utility::LogInfo(
            "Bounding box is: ({:.4f}, {:.4f}, {:.4f}) - ({:.4f}, {:.4f}, "
            "{:.4f})",
            min_bound(0), min_bound(1), min_bound(2), max_bound(0),
            max_bound(1), max_bound(2));

    for (size_t i = 0; i < pointcloud.points_.size(); i++) {
        if (pointcloud_has_normal) {
            const Eigen::Vector3d &point = pointcloud.points_[i];
            const Eigen::Vector3d &normal = pointcloud.normals_[i];
            utility::LogInfo("{:.6f} {:.6f} {:.6f} {:.6f} {:.6f} {:.6f}",
                             point(0), point(1), point(2), normal(0), normal(1),
                             normal(2));
        } else {
            const Eigen::Vector3d &point = pointcloud.points_[i];
            utility::LogInfo("{:.6f} {:.6f} {:.6f}", point(0), point(1),
                             point(2));
        }
    }
    utility::LogInfo("End of the list.");
}

void PrintHelp() {
    using namespace open3d;

    PrintOpen3DVersion();
    // clang-format off
    utility::LogInfo("Usage:");
    utility::LogInfo("    > PointCloud [pointcloud_filename]");
    // clang-format on
    utility::LogInfo("");
}

int main(int argc, char *argv[]) {
    using namespace open3d;

    utility::SetVerbosityLevel(utility::VerbosityLevel::Debug);

    if (argc != 2 ||
        utility::ProgramOptionExistsAny(argc, argv, {"-h", "--help"})) {
        PrintHelp();
        return 1;
    }

    auto pcd = io::CreatePointCloudFromFile(argv[1]);

    utility::LogInfo("End of the test.");
    return 0;
}
