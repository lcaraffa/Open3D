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

#include <rply.h>

#include "open3d/io/FileFormatIO.h"
#include "open3d/io/LineSetIO.h"
#include "open3d/io/PointCloudIO.h"
#include "open3d/io/TriangleMeshIO.h"
#include "open3d/io/VoxelGridIO.h"
#include "open3d/utility/Logging.h"
#include "open3d/utility/ProgressBar.h"
#include "open3d/utility/ProgressReporters.h"

namespace open3d {

namespace io {

/// @cond
namespace {



bool ReadPointCloudFromLAS(const std::string &filename,
                           geometry::PointCloud &pointcloud,
                           const ReadPointCloudOption &params) {
    using namespace ply_pointcloud_reader;


    return true;
}



}  // namespace io
}  // namespace open3d
