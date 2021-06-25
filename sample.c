/*
 * tiSample.c
 *
 * Sample JVMTI agent to demonstrate the IBM JVMTI dump extensions
 */

#include <stdio.h>
#include "jvmti.h"

#define LOG(s)  { printf s; printf("\n"); fflush(stdout); }

JNIEXPORT jint JNICALL Agent_OnLoad(JavaVM *jvm, char *options, void *reserved) {

	jvmtiEnv *jvmti = NULL;
	jvmtiError rc;
	int i = 0, j = 0;

	LOG(("Loading JVMTI sample agent\n"));

	(*jvm)->GetEnv(jvm, (void **)&jvmti, JVMTI_VERSION_1_0);

     	return JNI_OK;

}

