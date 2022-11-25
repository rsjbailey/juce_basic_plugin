juce_add_plugin(plugin_example
        COMPANY_NAME "test.rd.bbc.co.uk"
        FORMATS VST3
        IS_SYNTH FALSE
        COPY_PLUGIN_AFTER_BUILD TRUE
        PLUGIN_CODE T31q
        VST3_CATEGORIES Fx)

target_link_libraries(plugin_example PRIVATE juce::juce_audio_utils mylib)

target_sources(plugin_example PRIVATE processor.cpp)

target_compile_definitions(plugin_example
        PUBLIC
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_plugin` call
        JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_plugin` call
        JUCE_VST3_CAN_REPLACE_VST2=0
        )
