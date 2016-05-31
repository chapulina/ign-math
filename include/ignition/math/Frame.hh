/*
 * Copyright (C) 2016 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef IGNITION_MATH_FRAME_HH_
#define IGNITION_MATH_FRAME_HH_

#include <string>
#include <memory>
#include <ignition/math/Pose3.hh>

namespace ignition
{
  namespace math
  {
    // Forward declare private data class
    class FramePrivate;

    /// \class Frame Frame.hh ignition/math/Frame.hh
    /// \brief A frame has an offset (a Pose3d) and a name
    /// Frames are typically composed inside the FrameGraph class.
    class IGNITION_VISIBLE Frame
    {
      /// \brief math::Frame("inf", math::Pose3d::Nan)
      public: static const Frame Nan;

      /// \brief Constructor
      public: Frame();

      /// \brief Copy constructor
      /// \param[in] _frame Frame to copy
      public: Frame(const Frame &_frame);

      /// \brief Constructor
      /// \param[in] _name Name of the frame
      /// \param[in] _pose Pose of the frame
      public: Frame(const std::string &_name,
                    const Pose3d &_pose = Pose3d::Zero);

      /// \brief Destructor.
      public: virtual ~Frame();

      /// \brief Get the name of the frame.
      /// \return Name of the frame.
      public: std::string Name() const;

      /// \brief Set the name of the frame.
      /// \param[in] _name Name of the frame.
      public: void SetName(const std::string &_name);

      /// \brief Get the pose of the frame.
      /// \return Pose of the frame.
      public: Pose3d Pose() const;

      /// \brief Set the pose of the frame.
      /// \param[in] _pose Pose of the frame.
      public: void SetPose(const Pose3d &_pose);

      /// \brief Equality operator.
      /// \param[in] _frame Frame to compare against.
      /// \return True if this frame and _frame are equal.
      public: bool operator==(const Frame &_frame) const;

      /// \brief Inequality operator.
      /// \param[in] _frame Frame to compare against.
      /// \return False if this frame and _frame are equal.
      public: bool operator!=(const Frame &_frame) const;

      /// \brief Stream insertion operator
      /// \param _out output stream
      /// \param _pt Frame to output
      /// \return the stream
      public: friend std::ostream &operator<<(
                  std::ostream &_out, const ignition::math::Frame &_f)
      {
        _out << _f.Name() << " = " << _f.Pose();
        return _out;
      }

      /// \internal
      /// \brief Private data pointer.
      private: std::unique_ptr<FramePrivate> dataPtr;
    };
  }
}
#endif