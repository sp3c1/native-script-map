{
    "targets": [
        {
            "target_name": "addon",
            "sources": ["string-low-level.cc", "string-low-level-lib.cc", "string-low-level-lib-wrapper.cc" ],
            "cflags!": [ '-fno-exceptions' ],
            "cflags_cc!": [ '-fno-exceptions' ],
            "conditions": [
                ['OS=="mac"', {
                'xcode_settings': {
                    'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
                    'MACOSX_DEPLOYMENT_TARGET': '10.7',
                    'OTHER_CFLAGS': ['-std=c++11','-stdlib=libc++'],
                }
                }]
            ],
            "include_dirs" : [ "<!(node -e \"require('nan')\")" ]
            
        }    
    ]
}