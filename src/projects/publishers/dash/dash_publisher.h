//==============================================================================
//
//  OvenMediaEngine
//
//  Created by Jaejong Bong
//  Copyright (c) 2019 AirenSoft. All rights reserved.
//
//==============================================================================
#pragma once

#include "../segment_publisher.h"

class DashPublisher : public SegmentPublisher
{
public:
	static std::shared_ptr<DashPublisher> Create(std::map<int, std::shared_ptr<HttpServer>> &http_server_manager,
												 const info::Application *application_info,
												 std::shared_ptr<MediaRouteInterface> router);

	DashPublisher(PrivateToken token, const info::Application *application_info, std::shared_ptr<MediaRouteInterface> router);

protected:
	//--------------------------------------------------------------------
	// Implementation of SegmentPublisher
	//--------------------------------------------------------------------
	bool Start(std::map<int, std::shared_ptr<HttpServer>> &http_server_manager);

	//--------------------------------------------------------------------
	// Implementation of Publisher
	//--------------------------------------------------------------------
	std::shared_ptr<Application> OnCreateApplication(const info::Application *application_info) override;

	cfg::PublisherType GetPublisherType() const override
	{
		return cfg::PublisherType::Dash;
	}

	const char *GetPublisherName() const override
	{
		return "CMAF";
	}
};