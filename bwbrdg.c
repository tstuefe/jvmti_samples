/*
 * tiSample.c
 *
 * Sample JVMTI agent to demonstrate the IBM JVMTI dump extensions
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include "jvmti.h"

#define LOG(s)  { printf s; printf("\n"); fflush(stdout); }

volatile void* p1 = NULL;
volatile void* p2 = NULL;

static void leak_malloc() {
	for (int i = 0; i < 1024; i ++) 
		p1 = malloc(rand() % 32);
}

static void leakleak() {
	leak_malloc();
}

static void and_leak_like_you_dont_care() {
	leakleak();
}

static void throw_your_hands_in_the_air() {
	and_leak_like_you_dont_care();
}

static void* leaky_thread(void* dummy) {
	for (;;) {
		throw_your_hands_in_the_air();
		sleep(1);
	}
}

static void start_leaky_thread() {
	int rc = 0;
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	rc = pthread_create(&tid, &attr, leaky_thread, NULL);
	if (rc == 0) {
		LOG(("started leaky thread"));
	} else {
		LOG(("thread start failure %d", errno));
	}
}

JNIEXPORT jint JNICALL Agent_OnLoad(JavaVM *jvm, char *options, void *reserved) {

	jvmtiEnv *jvmti = NULL;
	jvmtiError rc;
	int i = 0, j = 0;

	LOG(("Loading JVMTI sample agent\n"));

	start_leaky_thread();

	(*jvm)->GetEnv(jvm, (void **)&jvmti, JVMTI_VERSION_1_0);

     	return JNI_OK;

}

