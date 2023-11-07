//
// Copyright (c) Oneiro Games. All rights reserved.
// Licensed under the GNU General Public License, Version 3.0.
//

#pragma once

#include "Renderer.hpp"

namespace oe::Renderer
{
	/// @brief An object that encapsulates the state needed to issue draws
	class IGraphicsPipeline
	{
	public:
		virtual void Create(const GraphicsPipelineInfo& info) = 0;
		IGraphicsPipeline() = default;
		virtual ~IGraphicsPipeline() = default;
		IGraphicsPipeline(IGraphicsPipeline&& old) noexcept = default;
		IGraphicsPipeline& operator=(IGraphicsPipeline&& old) noexcept = default;
		IGraphicsPipeline(const IGraphicsPipeline&) = delete;
		IGraphicsPipeline& operator=(const IGraphicsPipeline&) = delete;

		bool operator==(const IGraphicsPipeline&) const = default;
	};

	/// @brief An object that encapsulates the state needed to issue dispatches
	class IComputePipeline
	{
	public:
		virtual void Create(const ComputePipelineInfo& info) = 0;
		IComputePipeline() = default;
		virtual ~IComputePipeline() = default;
		IComputePipeline(IComputePipeline&& old) noexcept = default;
		IComputePipeline& operator=(IComputePipeline&& old) noexcept = default;
		IComputePipeline(const IComputePipeline&) = delete;
		IComputePipeline& operator=(const IComputePipeline&) = delete;

		bool operator==(const IComputePipeline&) const = default;

		[[nodiscard]] virtual Extent3D WorkgroupSize() const
		{
			return {};
		};
	};
} // namespace oe::Renderer