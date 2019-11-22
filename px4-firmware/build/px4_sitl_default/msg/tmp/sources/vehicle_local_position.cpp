/****************************************************************************
 *
 *   Copyright (C) 2013-2016 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/* Auto-generated by genmsg_cpp from file vehicle_local_position.msg */


#include <inttypes.h>
#include <px4_platform_common/log.h>
#include <px4_platform_common/defines.h>
#include <uORB/topics/vehicle_local_position.h>
#include <drivers/drv_hrt.h>
#include <lib/drivers/device/Device.hpp>

constexpr char __orb_vehicle_local_position_fields[] = "uint64_t timestamp;uint64_t ref_timestamp;double ref_lat;double ref_lon;float x;float y;float z;float[2] delta_xy;float delta_z;float vx;float vy;float vz;float z_deriv;float[2] delta_vxy;float delta_vz;float ax;float ay;float az;float yaw;float ref_alt;float dist_bottom;float dist_bottom_rate;float eph;float epv;float evh;float evv;float vxy_max;float vz_max;float hagl_min;float hagl_max;bool xy_valid;bool z_valid;bool v_xy_valid;bool v_z_valid;uint8_t xy_reset_counter;uint8_t z_reset_counter;uint8_t vxy_reset_counter;uint8_t vz_reset_counter;bool xy_global;bool z_global;bool dist_bottom_valid;uint8_t[5] _padding0;";

ORB_DEFINE(vehicle_local_position, struct vehicle_local_position_s, 155, __orb_vehicle_local_position_fields);
ORB_DEFINE(vehicle_local_position_groundtruth, struct vehicle_local_position_s, 155, __orb_vehicle_local_position_fields);


void print_message(const vehicle_local_position_s& message)
{

	PX4_INFO_RAW(" vehicle_local_position_s\n");
	if (message.timestamp != 0) {
		PX4_INFO_RAW("\ttimestamp: %" PRIu64 "  (%.6f seconds ago)\n", message.timestamp, hrt_elapsed_time(&message.timestamp) / 1e6);
	} else {
		PX4_INFO_RAW("\n");
	}
	PX4_INFO_RAW("\tref_timestamp: %" PRIu64 "\n", message.ref_timestamp);
	PX4_INFO_RAW("\tref_lat: %.6f\n", message.ref_lat);
	PX4_INFO_RAW("\tref_lon: %.6f\n", message.ref_lon);
	PX4_INFO_RAW("\tx: %.4f\n", (double)message.x);
	PX4_INFO_RAW("\ty: %.4f\n", (double)message.y);
	PX4_INFO_RAW("\tz: %.4f\n", (double)message.z);
	PX4_INFO_RAW("\tdelta_xy: [%.4f, %.4f]\n", (double)message.delta_xy[0], (double)message.delta_xy[1]);
	PX4_INFO_RAW("\tdelta_z: %.4f\n", (double)message.delta_z);
	PX4_INFO_RAW("\tvx: %.4f\n", (double)message.vx);
	PX4_INFO_RAW("\tvy: %.4f\n", (double)message.vy);
	PX4_INFO_RAW("\tvz: %.4f\n", (double)message.vz);
	PX4_INFO_RAW("\tz_deriv: %.4f\n", (double)message.z_deriv);
	PX4_INFO_RAW("\tdelta_vxy: [%.4f, %.4f]\n", (double)message.delta_vxy[0], (double)message.delta_vxy[1]);
	PX4_INFO_RAW("\tdelta_vz: %.4f\n", (double)message.delta_vz);
	PX4_INFO_RAW("\tax: %.4f\n", (double)message.ax);
	PX4_INFO_RAW("\tay: %.4f\n", (double)message.ay);
	PX4_INFO_RAW("\taz: %.4f\n", (double)message.az);
	PX4_INFO_RAW("\tyaw: %.4f\n", (double)message.yaw);
	PX4_INFO_RAW("\tref_alt: %.4f\n", (double)message.ref_alt);
	PX4_INFO_RAW("\tdist_bottom: %.4f\n", (double)message.dist_bottom);
	PX4_INFO_RAW("\tdist_bottom_rate: %.4f\n", (double)message.dist_bottom_rate);
	PX4_INFO_RAW("\teph: %.4f\n", (double)message.eph);
	PX4_INFO_RAW("\tepv: %.4f\n", (double)message.epv);
	PX4_INFO_RAW("\tevh: %.4f\n", (double)message.evh);
	PX4_INFO_RAW("\tevv: %.4f\n", (double)message.evv);
	PX4_INFO_RAW("\tvxy_max: %.4f\n", (double)message.vxy_max);
	PX4_INFO_RAW("\tvz_max: %.4f\n", (double)message.vz_max);
	PX4_INFO_RAW("\thagl_min: %.4f\n", (double)message.hagl_min);
	PX4_INFO_RAW("\thagl_max: %.4f\n", (double)message.hagl_max);
	PX4_INFO_RAW("\txy_valid: %s\n", (message.xy_valid ? "True" : "False"));
	PX4_INFO_RAW("\tz_valid: %s\n", (message.z_valid ? "True" : "False"));
	PX4_INFO_RAW("\tv_xy_valid: %s\n", (message.v_xy_valid ? "True" : "False"));
	PX4_INFO_RAW("\tv_z_valid: %s\n", (message.v_z_valid ? "True" : "False"));
	PX4_INFO_RAW("\txy_reset_counter: %u\n", message.xy_reset_counter);
	PX4_INFO_RAW("\tz_reset_counter: %u\n", message.z_reset_counter);
	PX4_INFO_RAW("\tvxy_reset_counter: %u\n", message.vxy_reset_counter);
	PX4_INFO_RAW("\tvz_reset_counter: %u\n", message.vz_reset_counter);
	PX4_INFO_RAW("\txy_global: %s\n", (message.xy_global ? "True" : "False"));
	PX4_INFO_RAW("\tz_global: %s\n", (message.z_global ? "True" : "False"));
	PX4_INFO_RAW("\tdist_bottom_valid: %s\n", (message.dist_bottom_valid ? "True" : "False"));
	
}
