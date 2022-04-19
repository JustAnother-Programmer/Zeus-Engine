#pragma once

class IApplication
{
public:
	IApplication();
	virtual ~IApplication() = 0;

public:
	// Called to initialize the application
	virtual VOID Initialize() = 0;

	// Called on a loop when the application is running
	virtual VOID Update() = 0;
};