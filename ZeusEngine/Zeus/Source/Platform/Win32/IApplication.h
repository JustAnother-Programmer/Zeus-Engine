#pragma once

#define ENTRYAPP(app) IApplication* EntryApplication() { return new app; }

class ZEUS_API IApplication
{
public:
	IApplication();
	virtual ~IApplication() {};

public:
	// Called to initialize the application
	virtual VOID Initialize() = 0;

	// Called on a loop when the application is running
	virtual VOID Update() = 0;
};

IApplication* EntryApplication();