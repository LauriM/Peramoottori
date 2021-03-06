#ifndef APPLICATION_H
#define APPLICATION_H

#include <cstddef>
#include <android/log.h>
#include <android/sensor.h>
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "Info", __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "Warning", __VA_ARGS__))

#include <android_native_app_glue.h>
#include <android/asset_manager.h>
#include <EGL/egl.h>

namespace pm
{
	/// The core application system.
	/**
	Handles most of the communication with java side. 
		-Create an Application instance.
		-use the Initialize.
		-Create your mainloop with while(app.Update)
	*/
	class Application
	{
	public:
		/// Default Constructor.
		Application();

		/// Initializing the Application.
		/**
			\param application takes in the android_app
		*/
		void Initialize(android_app* application);

		/// The core update loop.
		/**
			You can construct the main loop of your game using the update, place it in while(app.Update).
			\return Returns true as default, when TerminateDisplay is called, returns false.
		*/
		bool Update();

		/// Handles swapping buffers if the display is initialized.
		/**
			TODO
		*/
		void DrawFrame();

		/// Returns Android AssetManager for use outside of this class.
		/**
			\return Returns the AAssetManager*
		*/
		AAssetManager* GetAssetManager();

		/// Struct that holds application information and can be stored on java side.
		struct Engine
		{
			struct android_app* app;
			AAssetManager* assetManager;
			Application* applicationPointer;

			EGLDisplay display;
			EGLSurface surface;
			EGLContext context;

			ASensorManager* sensorManager;
			const ASensor* accelerometerSensor;
			ASensorEventQueue* sensorEventQueue;

			int width;
			int height;

			Engine() : app(nullptr), assetManager(nullptr), display(EGL_NO_DISPLAY),
				surface(EGL_NO_SURFACE), context(EGL_NO_SURFACE), width(0), height(0) {};
		};

		/// Called when APP_CMD_TERM_WINDOW is received by processCommand.
		/**
			Destroys the egl Context, Surface and terminates the Display when done.
		*/
		void TerminateDisplay();

		/// Called when APP_CMD_INIT_WINDOW is received by processCommand.
		/**
			Initializes the EGL surface, display and context, Stores them in Engine.
			\return Returns -1 if failed to make the display, surface and context current. Returns 0 if succesful.
		*/
		int InitializeDisplay();


		/// Returns engine for use outside of this class.
		/**

		*/
		Engine* GetEngine();

	private:
		/// The engine struct used to store data between native and android side.
		Engine engine;
		/// Used by Update() 
		android_poll_source* eventSource;
	};
}

#endif