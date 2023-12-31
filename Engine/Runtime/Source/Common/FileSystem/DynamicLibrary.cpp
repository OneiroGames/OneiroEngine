//
// Copyright (c) Oneiro Games. All rights reserved.
// Licensed under the GNU General Public License, Version 3.0.
//

#include "Oneiro/Common/FileSystem/DynamicLibrary.hpp"

#include "Oneiro/Common/Common.hpp"

namespace oe::FileSystem
{
	bool DynamicLibrary::Load(const std::string& path)
	{
		m_Module = LoadLibrary((path).c_str());
		return m_Module && m_Module != INVALID_HANDLE_VALUE;
	}

	void DynamicLibrary::Close()
	{
		FreeLibrary(m_Module);
	}
} // namespace oe::FileSystem