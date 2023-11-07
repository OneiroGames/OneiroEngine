//
// Copyright (c) Oneiro Games. All rights reserved.
// Licensed under the GNU General Public License, Version 3.0.
//

#pragma once

#include "Oneiro/Common/Common.hpp"

#include <array>
#include <span>
#include <variant>

#define OE_DECLARE_FLAG_TYPE(FLAG_TYPE, FLAG_BITS, BASE_TYPE)                                 \
                                                                                              \
	struct FLAG_TYPE                                                                          \
	{                                                                                         \
		BASE_TYPE flags = static_cast<BASE_TYPE>(0);                                          \
                                                                                              \
		constexpr FLAG_TYPE() noexcept = default;                                             \
		constexpr explicit FLAG_TYPE(BASE_TYPE in) noexcept : flags(in) {}                    \
		constexpr FLAG_TYPE(FLAG_BITS in) noexcept : flags(static_cast<BASE_TYPE>(in)) {}     \
		constexpr bool operator==(FLAG_TYPE const& right) const                               \
		{                                                                                     \
			return flags == right.flags;                                                      \
		}                                                                                     \
		constexpr bool operator!=(FLAG_TYPE const& right) const                               \
		{                                                                                     \
			return flags != right.flags;                                                      \
		}                                                                                     \
		constexpr explicit operator BASE_TYPE() const                                         \
		{                                                                                     \
			return flags;                                                                     \
		}                                                                                     \
		constexpr explicit operator bool() const noexcept                                     \
		{                                                                                     \
			return flags != 0;                                                                \
		}                                                                                     \
	};                                                                                        \
	constexpr FLAG_TYPE operator|(FLAG_TYPE a, FLAG_TYPE b) noexcept                          \
	{                                                                                         \
		return static_cast<FLAG_TYPE>(a.flags | b.flags);                                     \
	}                                                                                         \
	constexpr FLAG_TYPE operator&(FLAG_TYPE a, FLAG_TYPE b) noexcept                          \
	{                                                                                         \
		return static_cast<FLAG_TYPE>(a.flags & b.flags);                                     \
	}                                                                                         \
	constexpr FLAG_TYPE operator^(FLAG_TYPE a, FLAG_TYPE b) noexcept                          \
	{                                                                                         \
		return static_cast<FLAG_TYPE>(a.flags ^ b.flags);                                     \
	}                                                                                         \
	constexpr FLAG_TYPE operator~(FLAG_TYPE a) noexcept                                       \
	{                                                                                         \
		return static_cast<FLAG_TYPE>(~a.flags);                                              \
	}                                                                                         \
	constexpr FLAG_TYPE& operator|=(FLAG_TYPE& a, FLAG_TYPE b) noexcept                       \
	{                                                                                         \
		a.flags = (a.flags | b.flags);                                                        \
		return a;                                                                             \
	}                                                                                         \
	constexpr FLAG_TYPE& operator&=(FLAG_TYPE& a, FLAG_TYPE b) noexcept                       \
	{                                                                                         \
		a.flags = (a.flags & b.flags);                                                        \
		return a;                                                                             \
	}                                                                                         \
	constexpr FLAG_TYPE operator^=(FLAG_TYPE& a, FLAG_TYPE b) noexcept                        \
	{                                                                                         \
		a.flags = (a.flags ^ b.flags);                                                        \
		return a;                                                                             \
	}                                                                                         \
	constexpr FLAG_TYPE operator|(FLAG_BITS a, FLAG_BITS b) noexcept                          \
	{                                                                                         \
		return static_cast<FLAG_TYPE>(static_cast<BASE_TYPE>(a) | static_cast<BASE_TYPE>(b)); \
	}                                                                                         \
	constexpr FLAG_TYPE operator&(FLAG_BITS a, FLAG_BITS b) noexcept                          \
	{                                                                                         \
		return static_cast<FLAG_TYPE>(static_cast<BASE_TYPE>(a) & static_cast<BASE_TYPE>(b)); \
	}                                                                                         \
	constexpr FLAG_TYPE operator~(FLAG_BITS key) noexcept                                     \
	{                                                                                         \
		return static_cast<FLAG_TYPE>(~static_cast<BASE_TYPE>(key));                          \
	}                                                                                         \
	constexpr FLAG_TYPE operator^(FLAG_BITS a, FLAG_BITS b) noexcept                          \
	{                                                                                         \
		return static_cast<FLAG_TYPE>(static_cast<BASE_TYPE>(a) ^ static_cast<BASE_TYPE>(b)); \
	}

namespace oe::Renderer
{
	class IShader;
	class IBuffer;
	class IGraphicsPipeline;
	class IComputePipeline;
	class ITexture;
	class ICommandBuffer;
	class IRenderPass;

	struct Extent2D
	{
		uint32_t width{};
		uint32_t height{};
		bool operator==(const Extent2D&) const noexcept = default;
		Extent2D operator+(const Extent2D& other) const
		{
			return {width + other.width, height + other.height};
		}
		Extent2D operator-(const Extent2D& other) const
		{
			return {width - other.width, height - other.height};
		}
		Extent2D operator*(const Extent2D& other) const
		{
			return {width * other.width, height * other.height};
		}
		Extent2D operator/(const Extent2D& other) const
		{
			return {width / other.width, height / other.height};
		}
		Extent2D operator>>(const Extent2D& other) const
		{
			return {width >> other.width, height >> other.height};
		}
		Extent2D operator<<(const Extent2D& other) const
		{
			return {width << other.width, height << other.height};
		}
		Extent2D operator+(uint32_t val) const
		{
			return *this + Extent2D{val, val};
		}
		Extent2D operator-(uint32_t val) const
		{
			return *this - Extent2D{val, val};
		}
		Extent2D operator*(uint32_t val) const
		{
			return *this * Extent2D{val, val};
		}
		Extent2D operator/(uint32_t val) const
		{
			return *this / Extent2D{val, val};
		}
		Extent2D operator>>(uint32_t val) const
		{
			return *this >> Extent2D{val, val};
		}
		Extent2D operator<<(uint32_t val) const
		{
			return *this << Extent2D{val, val};
		}
	};

	inline Extent2D operator+(uint32_t val, Extent2D ext)
	{
		return ext + val;
	}
	inline Extent2D operator-(uint32_t val, Extent2D ext)
	{
		return ext - val;
	}
	inline Extent2D operator*(uint32_t val, Extent2D ext)
	{
		return ext * val;
	}
	inline Extent2D operator/(uint32_t val, Extent2D ext)
	{
		return ext / val;
	}
	inline Extent2D operator>>(uint32_t val, Extent2D ext)
	{
		return ext >> val;
	}
	inline Extent2D operator<<(uint32_t val, Extent2D ext)
	{
		return ext << val;
	}

	struct Extent3D
	{
		uint32_t width{};
		uint32_t height{};
		uint32_t depth{};

		operator Extent2D() const
		{
			return {width, height};
		}
		bool operator==(const Extent3D&) const noexcept = default;
		Extent3D operator+(const Extent3D& other) const
		{
			return {width + other.width, height + other.height, depth + other.depth};
		}
		Extent3D operator-(const Extent3D& other) const
		{
			return {width - other.width, height - other.height, depth - other.depth};
		}
		Extent3D operator*(const Extent3D& other) const
		{
			return {width * other.width, height * other.height, depth * other.depth};
		}
		Extent3D operator/(const Extent3D& other) const
		{
			return {width / other.width, height / other.height, depth / other.depth};
		}
		Extent3D operator>>(const Extent3D& other) const
		{
			return {width >> other.width, height >> other.height, depth >> other.depth};
		}
		Extent3D operator<<(const Extent3D& other) const
		{
			return {width << other.width, height << other.height, depth << other.depth};
		}
		Extent3D operator+(uint32_t val) const
		{
			return *this + Extent3D{val, val, val};
		}
		Extent3D operator-(uint32_t val) const
		{
			return *this - Extent3D{val, val, val};
		}
		Extent3D operator*(uint32_t val) const
		{
			return *this * Extent3D{val, val, val};
		}
		Extent3D operator/(uint32_t val) const
		{
			return *this / Extent3D{val, val, val};
		}
		Extent3D operator>>(uint32_t val) const
		{
			return *this >> Extent3D{val, val, val};
		}
		Extent3D operator<<(uint32_t val) const
		{
			return *this << Extent3D{val, val, val};
		}
	};

	inline Extent3D operator+(uint32_t val, Extent3D ext)
	{
		return ext + val;
	}
	inline Extent3D operator-(uint32_t val, Extent3D ext)
	{
		return ext - val;
	}
	inline Extent3D operator*(uint32_t val, Extent3D ext)
	{
		return ext * val;
	}
	inline Extent3D operator/(uint32_t val, Extent3D ext)
	{
		return ext / val;
	}
	inline Extent3D operator>>(uint32_t val, Extent3D ext)
	{
		return ext >> val;
	}
	inline Extent3D operator<<(uint32_t val, Extent3D ext)
	{
		return ext << val;
	}

	struct Offset2D
	{
		uint32_t x{};
		uint32_t y{};

		bool operator==(const Offset2D&) const noexcept = default;
		Offset2D operator+(const Offset2D& other) const
		{
			return {x + other.x, y + other.y};
		}
		Offset2D operator-(const Offset2D& other) const
		{
			return {x - other.x, y - other.y};
		}
		Offset2D operator*(const Offset2D& other) const
		{
			return {x * other.x, y * other.y};
		}
		Offset2D operator/(const Offset2D& other) const
		{
			return {x / other.x, y / other.y};
		}
		Offset2D operator>>(const Offset2D& other) const
		{
			return {x >> other.x, y >> other.y};
		}
		Offset2D operator<<(const Offset2D& other) const
		{
			return {x << other.x, y << other.y};
		}
		Offset2D operator+(uint32_t val) const
		{
			return *this + Offset2D{val, val};
		}
		Offset2D operator-(uint32_t val) const
		{
			return *this - Offset2D{val, val};
		}
		Offset2D operator*(uint32_t val) const
		{
			return *this * Offset2D{val, val};
		}
		Offset2D operator/(uint32_t val) const
		{
			return *this / Offset2D{val, val};
		}
		Offset2D operator>>(uint32_t val) const
		{
			return *this >> Offset2D{val, val};
		}
		Offset2D operator<<(uint32_t val) const
		{
			return *this << Offset2D{val, val};
		}
	};

	inline Offset2D operator+(uint32_t val, Offset2D ext)
	{
		return ext + val;
	}
	inline Offset2D operator-(uint32_t val, Offset2D ext)
	{
		return ext - val;
	}
	inline Offset2D operator*(uint32_t val, Offset2D ext)
	{
		return ext * val;
	}
	inline Offset2D operator/(uint32_t val, Offset2D ext)
	{
		return ext / val;
	}
	inline Offset2D operator>>(uint32_t val, Offset2D ext)
	{
		return ext >> val;
	}
	inline Offset2D operator<<(uint32_t val, Offset2D ext)
	{
		return ext << val;
	}

	struct Offset3D
	{
		uint32_t x{};
		uint32_t y{};
		uint32_t z{};

		operator Offset2D() const
		{
			return {x, y};
		}
		bool operator==(const Offset3D&) const noexcept = default;
		Offset3D operator+(const Offset3D& other) const
		{
			return {x + other.x, y + other.y, z + other.z};
		}
		Offset3D operator-(const Offset3D& other) const
		{
			return {x - other.x, y - other.y, z - other.z};
		}
		Offset3D operator*(const Offset3D& other) const
		{
			return {x * other.x, y * other.y, z * other.z};
		}
		Offset3D operator/(const Offset3D& other) const
		{
			return {x / other.x, y / other.y, z / other.z};
		}
		Offset3D operator>>(const Offset3D& other) const
		{
			return {x >> other.x, y >> other.y, z >> other.z};
		}
		Offset3D operator<<(const Offset3D& other) const
		{
			return {x << other.x, y << other.y, z << other.z};
		}
		Offset3D operator+(uint32_t val) const
		{
			return *this + Offset3D{val, val, val};
		}
		Offset3D operator-(uint32_t val) const
		{
			return *this - Offset3D{val, val, val};
		}
		Offset3D operator*(uint32_t val) const
		{
			return *this * Offset3D{val, val, val};
		}
		Offset3D operator/(uint32_t val) const
		{
			return *this / Offset3D{val, val, val};
		}
		Offset3D operator>>(uint32_t val) const
		{
			return *this >> Offset3D{val, val, val};
		}
		Offset3D operator<<(uint32_t val) const
		{
			return *this << Offset3D{val, val, val};
		}
	};

	inline Offset3D operator+(uint32_t val, Offset3D ext)
	{
		return ext + val;
	}
	inline Offset3D operator-(uint32_t val, Offset3D ext)
	{
		return ext - val;
	}
	inline Offset3D operator*(uint32_t val, Offset3D ext)
	{
		return ext * val;
	}
	inline Offset3D operator/(uint32_t val, Offset3D ext)
	{
		return ext / val;
	}
	inline Offset3D operator>>(uint32_t val, Offset3D ext)
	{
		return ext >> val;
	}
	inline Offset3D operator<<(uint32_t val, Offset3D ext)
	{
		return ext << val;
	}

	struct Rect2D
	{
		Offset2D offset;
		Extent2D extent;

		bool operator==(const Rect2D&) const noexcept = default;
	};

	enum class ImageType : uint32_t
	{
		TEX_1D,
		TEX_2D,
		TEX_3D,
		TEX_1D_ARRAY,
		TEX_2D_ARRAY,
		TEX_CUBEMAP,
		TEX_CUBEMAP_ARRAY,
		TEX_2D_MULTISAMPLE,
		TEX_2D_MULTISAMPLE_ARRAY,
	};

	/// @brief Specifies how a component is swizzled
	enum class ComponentSwizzle : uint32_t
	{
		ZERO,
		ONE,
		R,
		G,
		B,
		A
	};

	enum class Format : uint32_t
	{
		UNDEFINED,

		// Color formats
		R8_UNORM,
		R8_SNORM,
		R16_UNORM,
		R16_SNORM,
		R8G8_UNORM,
		R8G8_SNORM,
		R16G16_UNORM,
		R16G16_SNORM,
		R3G3B2_UNORM,
		R4G4B4_UNORM,
		R5G5B5_UNORM,
		R8G8B8_UNORM,
		R8G8B8_SNORM,
		R10G10B10_UNORM,
		R12G12B12_UNORM,
		R16G16B16_SNORM,
		R2G2B2A2_UNORM,
		R4G4B4A4_UNORM,
		R5G5B5A1_UNORM,
		R8G8B8A8_UNORM,
		R8G8B8A8_SNORM,
		R10G10B10A2_UNORM,
		R10G10B10A2_UINT,
		R12G12B12A12_UNORM,
		R16G16B16A16_UNORM,
		R16G16B16A16_SNORM,
		R8G8B8_SRGB,
		R8G8B8A8_SRGB,
		R16_FLOAT,
		R16G16_FLOAT,
		R16G16B16_FLOAT,
		R16G16B16A16_FLOAT,
		R32_FLOAT,
		R32G32_FLOAT,
		R32G32B32_FLOAT,
		R32G32B32A32_FLOAT,
		R11G11B10_FLOAT,
		R9G9B9_E5,
		R8_SINT,
		R8_UINT,
		R16_SINT,
		R16_UINT,
		R32_SINT,
		R32_UINT,
		R8G8_SINT,
		R8G8_UINT,
		R16G16_SINT,
		R16G16_UINT,
		R32G32_SINT,
		R32G32_UINT,
		R8G8B8_SINT,
		R8G8B8_UINT,
		R16G16B16_SINT,
		R16G16B16_UINT,
		R32G32B32_SINT,
		R32G32B32_UINT,
		R8G8B8A8_SINT,
		R8G8B8A8_UINT,
		R16G16B16A16_SINT,
		R16G16B16A16_UINT,
		R32G32B32A32_SINT,
		R32G32B32A32_UINT,

		// Depth & stencil formats
		D32_FLOAT,
		D32_UNORM,
		D24_UNORM,
		D16_UNORM,
		D32_FLOAT_S8_UINT,
		D24_UNORM_S8_UINT,

		// Compressed formats
		// DXT
		BC1_RGB_UNORM,
		BC1_RGB_SRGB,
		BC1_RGBA_UNORM,
		BC1_RGBA_SRGB,
		BC2_RGBA_UNORM,
		BC2_RGBA_SRGB,
		BC3_RGBA_UNORM,
		BC3_RGBA_SRGB,
		// RGTC
		BC4_R_UNORM,
		BC4_R_SNORM,
		BC5_RG_UNORM,
		BC5_RG_SNORM,
		// BPTC
		BC6H_RGB_UFLOAT,
		BC6H_RGB_SFLOAT,
		BC7_RGBA_UNORM,
		BC7_RGBA_SRGB,

		// TODO: 64-bits-per-component formats
	};

	// multisampling and anisotropy
	enum class SampleCount : uint32_t
	{
		SAMPLES_1 = 1,
		SAMPLES_2 = 2,
		SAMPLES_4 = 4,
		SAMPLES_8 = 8,
		SAMPLES_16 = 16,
		SAMPLES_32 = 32,
	};

	enum class UploadFormat : uint32_t
	{
		UNDEFINED,
		R,
		RG,
		RGB,
		BGR,
		RGBA,
		BGRA,
		R_INTEGER,
		RG_INTEGER,
		RGB_INTEGER,
		BGR_INTEGER,
		RGBA_INTEGER,
		BGRA_INTEGER,
		DEPTH_COMPONENT,
		STENCIL_INDEX,
		DEPTH_STENCIL,

		/// @brief For CopyTextureToBuffer and CopyBufferToTexture
		INFER_FORMAT,
	};

	enum class UploadType : uint32_t
	{
		UNDEFINED,
		UBYTE,
		SBYTE,
		USHORT,
		SSHORT,
		UINT,
		SINT,
		FLOAT,
		UBYTE_3_3_2,
		UBYTE_2_3_3_REV,
		USHORT_5_6_5,
		USHORT_5_6_5_REV,
		USHORT_4_4_4_4,
		USHORT_4_4_4_4_REV,
		USHORT_5_5_5_1,
		USHORT_1_5_5_5_REV,
		UINT_8_8_8_8,
		UINT_8_8_8_8_REV,
		UINT_10_10_10_2,
		UINT_2_10_10_10_REV,

		/// @brief For CopyTextureToBuffer and CopyBufferToTexture
		INFER_TYPE,
	};

	/// @brief Convenience constant to allow binding the whole buffer in Cmd::BindUniformBuffer and Cmd::BindStorageBuffer
	///
	/// If an offset is provided with this constant, then the range [offset, buffer.Size()) will be bound.
	constexpr inline uint64_t WHOLE_BUFFER = static_cast<uint64_t>(-1);

	enum class Filter : uint32_t
	{
		NONE,
		NEAREST,
		LINEAR,
	};

	enum class AddressMode : uint32_t
	{
		REPEAT,
		MIRRORED_REPEAT,
		CLAMP_TO_EDGE,
		CLAMP_TO_BORDER,
		MIRROR_CLAMP_TO_EDGE,
	};

	enum class BorderColor : uint32_t
	{
		FLOAT_TRANSPARENT_BLACK,
		INT_TRANSPARENT_BLACK,
		FLOAT_OPAQUE_BLACK,
		INT_OPAQUE_BLACK,
		FLOAT_OPAQUE_WHITE,
		INT_OPAQUE_WHITE,
	};

	enum class AspectMaskBit : uint32_t
	{
		COLOR_BUFFER_BIT = 1 << 0,
		DEPTH_BUFFER_BIT = 1 << 1,
		STENCIL_BUFFER_BIT = 1 << 2,
	};

	enum class PrimitiveTopology : uint32_t
	{
		POINT_LIST,
		LINE_LIST,
		LINE_STRIP,
		TRIANGLE_LIST,
		TRIANGLE_STRIP,
		TRIANGLE_FAN,

		/// @note Available only in pipelines with tessellation shaders
		PATCH_LIST,
	};

	enum class PolygonMode : uint32_t
	{
		FILL,
		LINE,
		POINT,
	};

	enum class CullMode : uint32_t
	{
		NONE = 0b00,
		FRONT = 0b01,
		BACK = 0b10,
		FRONT_AND_BACK = 0b11,
	};

	enum class FrontFace : uint32_t
	{
		CLOCKWISE,
		COUNTERCLOCKWISE,
	};

	enum class CompareOp : uint32_t
	{
		NEVER,
		LESS,
		EQUAL,
		LESS_OR_EQUAL,
		GREATER,
		NOT_EQUAL,
		GREATER_OR_EQUAL,
		ALWAYS,
	};

	enum class LogicOp : uint32_t
	{
		CLEAR,
		SET,
		COPY,
		COPY_INVERTED,
		NO_OP,
		INVERT,
		AND,
		NAND,
		OR,
		NOR,
		XOR,
		EQUIVALENT,
		AND_REVERSE,
		OR_REVERSE,
		AND_INVERTED,
		OR_INVERTED,
	};

	enum class BlendFactor : uint32_t
	{
		ZERO,
		ONE,
		SRC_COLOR,
		ONE_MINUS_SRC_COLOR,
		DST_COLOR,
		ONE_MINUS_DST_COLOR,
		SRC_ALPHA,
		ONE_MINUS_SRC_ALPHA,
		DST_ALPHA,
		ONE_MINUS_DST_ALPHA,
		CONSTANT_COLOR,
		ONE_MINUS_CONSTANT_COLOR,
		CONSTANT_ALPHA,
		ONE_MINUS_CONSTANT_ALPHA,
		SRC_ALPHA_SATURATE,
		SRC1_COLOR,
		ONE_MINUS_SRC1_COLOR,
		SRC1_ALPHA,
		ONE_MINUS_SRC1_ALPHA,
	};

	enum class BlendOp : uint32_t
	{
		ADD,
		SUBTRACT,
		REVERSE_SUBTRACT,
		MIN,
		MAX,
	};

	enum class ColorComponentFlag : uint32_t
	{
		NONE,
		R_BIT = 0b0001,
		G_BIT = 0b0010,
		B_BIT = 0b0100,
		A_BIT = 0b1000,
		RGBA_BITS = 0b1111,
	};

	enum class IndexType : uint32_t
	{
		UNSIGNED_BYTE,
		UNSIGNED_SHORT,
		UNSIGNED_INT,
	};

	enum class MemoryBarrierBit : uint32_t
	{
		NONE = 0,
		VERTEX_BUFFER_BIT = 1 << 0,	  // GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
		INDEX_BUFFER_BIT = 1 << 1,	  // GL_ELEMENT_ARRAY_BARRIER_BIT
		UNIFORM_BUFFER_BIT = 1 << 2,  // GL_UNIFORM_BARRIER_BIT
		TEXTURE_FETCH_BIT = 1 << 3,	  // GL_TEXTURE_FETCH_BARRIER_BIT
		IMAGE_ACCESS_BIT = 1 << 4,	  // GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
		COMMAND_BUFFER_BIT = 1 << 5,  // GL_COMMAND_BARRIER_BIT
		TEXTURE_UPDATE_BIT = 1 << 6,  // GL_TEXTURE_UPDATE_BARRIER_BIT
		BUFFER_UPDATE_BIT = 1 << 7,	  // GL_BUFFER_UPDATE_BARRIER_BIT
		MAPPED_BUFFER_BIT = 1 << 8,	  // GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
		FRAMEBUFFER_BIT = 1 << 9,	  // GL_FRAMEBUFFER_BARRIER_BIT
		SHADER_STORAGE_BIT = 1 << 10, // GL_SHADER_STORAGE_BARRIER_BIT
		QUERY_COUNTER_BIT = 1 << 11,  // GL_QUERY_BUFFER_BARRIER_BIT
		ALL_BITS = static_cast<uint32_t>(-1),
		// TODO: add more bits as necessary
	};

	enum class StencilOp : uint32_t
	{
		KEEP = 0,
		ZERO = 1,
		REPLACE = 2,
		INCREMENT_AND_CLAMP = 3,
		DECREMENT_AND_CLAMP = 4,
		INVERT = 5,
		INCREMENT_AND_WRAP = 6,
		DECREMENT_AND_WRAP = 7,
	};

	struct DrawIndirectCommand
	{
		uint32_t vertexCount;
		uint32_t instanceCount;
		uint32_t firstVertex;
		uint32_t firstInstance;
	};

	struct DrawIndexedIndirectCommand
	{
		uint32_t indexCount;
		uint32_t instanceCount;
		uint32_t firstIndex;
		int32_t vertexOffset;
		uint32_t firstInstance;
	};

	struct DispatchIndirectCommand
	{
		uint32_t groupCountX;
		uint32_t groupCountY;
		uint32_t groupCountZ;
	};

	enum class ClipDepthRange
	{
		NEGATIVE_ONE_TO_ONE, // OpenGL default
		ZERO_TO_ONE			 // D3D and Vulkan
	};

	/// @brief Parameters for Buffer::FillData
	struct BufferFillInfo
	{
		uint64_t offset = 0;
		uint64_t size = WHOLE_BUFFER;
		uint32_t data = 0;
	};

	enum class BufferStorageFlag : uint32_t
	{
		NONE = 0,

		/// @brief Allows the user to update the buffer's contents with Buffer::UpdateData
		DYNAMIC_STORAGE = 1 << 0,

		/// @brief Hints to the implementation to place the buffer storage in host memory
		CLIENT_STORAGE = 1 << 1,

		/// @brief Maps the buffer (persistently and coherently) upon creation
		MAP_MEMORY = 1 << 2,
	};

	struct InputAssemblyState
	{
		PrimitiveTopology topology = PrimitiveTopology::TRIANGLE_LIST;
		bool primitiveRestartEnable = false;
	};

	struct VertexInputBindingDescription
	{
		uint32_t location; // glEnableVertexArrayAttrib + glVertexArrayAttribFormat
		uint32_t binding;  // glVertexArrayAttribBinding
		Format format;	   // glVertexArrayAttribFormat
		uint32_t offset;   // glVertexArrayAttribFormat
	};

	struct VertexInputState
	{
		std::span<const VertexInputBindingDescription> vertexBindingDescriptions = {};
	};

	struct TessellationState
	{
		uint32_t patchControlPoints; // glPatchParameteri(GL_PATCH_VERTICES, ...)
	};

	struct RasterizationState
	{
		bool depthClampEnable = false;
		PolygonMode polygonMode = PolygonMode::FILL;
		CullMode cullMode = CullMode::BACK;
		FrontFace frontFace = FrontFace::COUNTERCLOCKWISE;
		bool depthBiasEnable = false;
		float depthBiasConstantFactor = 0;
		float depthBiasSlopeFactor = 0;
		float lineWidth = 1; // glLineWidth
		float pointSize = 1; // glPointSize
	};

	struct MultisampleState
	{
		bool sampleShadingEnable = false;	// glEnable(GL_SAMPLE_SHADING)
		float minSampleShading = 1;			// glMinSampleShading
		uint32_t sampleMask = 0xFFFFFFFF;	// glSampleMaski
		bool alphaToCoverageEnable = false; // glEnable(GL_SAMPLE_ALPHA_TO_COVERAGE)
		bool alphaToOneEnable = false;		// glEnable(GL_SAMPLE_ALPHA_TO_ONE)
	};

	struct DepthState
	{
		bool depthTestEnable = false;				// gl{Enable, Disable}(GL_DEPTH_TEST)
		bool depthWriteEnable = false;				// glDepthMask(depthWriteEnable)
		CompareOp depthCompareOp = CompareOp::LESS; // glDepthFunc
	};

	struct StencilOpState
	{
		StencilOp passOp = StencilOp::KEEP;		 // glStencilOp (dppass)
		StencilOp failOp = StencilOp::KEEP;		 // glStencilOp (sfail)
		StencilOp depthFailOp = StencilOp::KEEP; // glStencilOp (dpfail)
		CompareOp compareOp = CompareOp::ALWAYS; // glStencilFunc (func)
		uint32_t compareMask = 0;				 // glStencilFunc (mask)
		uint32_t writeMask = 0;					 // glStencilMask
		uint32_t reference = 0;					 // glStencilFunc (ref)

		bool operator==(const StencilOpState&) const noexcept = default;
	};

	struct StencilState
	{
		bool stencilTestEnable = false;
		StencilOpState front = {};
		StencilOpState back = {};
	};

	struct ColorBlendAttachmentState // glBlendFuncSeparatei + glBlendEquationSeparatei
	{
		bool blendEnable = false;														// if false, blend factor = one?
		BlendFactor srcColorBlendFactor = BlendFactor::ONE;								// srcRGB
		BlendFactor dstColorBlendFactor = BlendFactor::ZERO;							// dstRGB
		BlendOp colorBlendOp = BlendOp::ADD;											// modeRGB
		BlendFactor srcAlphaBlendFactor = BlendFactor::ONE;								// srcAlpha
		BlendFactor dstAlphaBlendFactor = BlendFactor::ZERO;							// dstAlpha
		BlendOp alphaBlendOp = BlendOp::ADD;											// modeAlpha
		uint32_t colorWriteMask = static_cast<uint32_t>(ColorComponentFlag::RGBA_BITS); // glColorMaski

		bool operator==(const ColorBlendAttachmentState&) const noexcept = default;
	};

	struct ColorBlendState
	{
		bool logicOpEnable = false;
		LogicOp logicOp = LogicOp::COPY;
		std::span<const ColorBlendAttachmentState> attachments = {};
		float blendConstants[4] = {0, 0, 0, 0};
	};

	/// @brief Parameters for the constructor of GraphicsPipeline
	struct GraphicsPipelineInfo
	{
		/// @brief An optional name for viewing in a graphics debugger
		std::string_view name;

		/// @brief Non-null pointer to a vertex shader
		const IShader* vertexShader = nullptr;

		/// @brief Optional pointer to a fragment shader
		const IShader* fragmentShader = nullptr;

		/// @brief Optional pointer to a tessellation control shader
		const IShader* tessellationControlShader = nullptr;

		/// @brief Optional pointer to a tessellation evaluation shader
		const IShader* tessellationEvaluationShader = nullptr;

		InputAssemblyState inputAssemblyState = {};
		VertexInputState vertexInputState = {};
		TessellationState tessellationState = {};
		RasterizationState rasterizationState = {};
		MultisampleState multisampleState = {};
		DepthState depthState = {};
		StencilState stencilState = {};
		ColorBlendState colorBlendState = {};
	};

	/// @brief Parameters for the constructor of ComputePipeline
	struct ComputePipelineInfo
	{
		/// @brief An optional name for viewing in a graphics debugger
		std::string_view name;

		/// @brief Non-null pointer to a compute shader
		const IShader* shader;
	};

	/// @brief Tells Fwog what to do with a render target at the beginning of a pass
	enum class AttachmentLoadOp : uint32_t
	{
		/// @brief The previous contents of the image will be preserved
		LOAD,

		/// @brief The contents of the image will be cleared to a uniform value
		CLEAR,

		/// @brief The previous contents of the image need not be preserved (they may be discarded)
		DONT_CARE,
	};

	struct ClearDepthStencilValue
	{
		float depth{};
		int32_t stencil{};
	};

	struct RenderColorAttachment
	{
		const ITexture* texture{};
		AttachmentLoadOp loadOp = AttachmentLoadOp::LOAD;
		std::array<float, 4> clearValue;
	};

	struct RenderDepthStencilAttachment
	{
		const ITexture* texture{};
		AttachmentLoadOp loadOp = AttachmentLoadOp::LOAD;
		ClearDepthStencilValue clearValue;
	};

	struct Viewport
	{
		Rect2D drawRect = {};
		float minDepth = 0.0f;
		float maxDepth = 1.0f;
		ClipDepthRange depthRange = ClipDepthRange::NEGATIVE_ONE_TO_ONE;

		bool operator==(const Viewport&) const noexcept = default;
	};

	// Describes the render targets that may be used in a draw
	struct RenderPassInfo
	{
		/// @brief An optional name to demarcate the pass in a graphics debugger
		std::string_view name;

		/// @brief An optional viewport
		///
		/// If empty, the viewport size will be the minimum the render targets' size and the offset will be 0.
		std::optional<Viewport> viewport = std::nullopt;
		std::span<const RenderColorAttachment> colorAttachments;
		std::optional<RenderDepthStencilAttachment> depthAttachment = std::nullopt;
		std::optional<RenderDepthStencilAttachment> stencilAttachment = std::nullopt;
	};

	struct RenderPassBeginInfo
	{
		/// @brief An optional name to demarcate the pass in a graphics debugger
		std::string_view name;
		Viewport viewport = {};
		AttachmentLoadOp colorLoadOp = AttachmentLoadOp::LOAD;
		std::array<float, 4> clearColorValue;
		AttachmentLoadOp depthLoadOp = AttachmentLoadOp::LOAD;
		float clearDepthValue = 0.0f;
		AttachmentLoadOp stencilLoadOp = AttachmentLoadOp::LOAD;
		int32_t clearStencilValue = 0;

		/// @brief If true, the linear->nonlinear sRGB OETF will be applied to pixels when rendering to the swapchain
		///
		/// This facility is provided because OpenGL does not expose the swapchain as an image we can interact with
		/// in the usual manner.
		bool enableSrgb = true;
	};

	OE_DECLARE_FLAG_TYPE(BufferStorageFlags, BufferStorageFlag, uint32_t);
} // namespace oe::Renderer