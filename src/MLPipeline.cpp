/**
 * @file    MLPipeline.cpp
 * @author  Sead Niksic
 */

#include "MLPipeline.h"

#include <torch/script.h>
#include <torch/torch.h>

namespace homey {

MLPipeline::MLPipeline(ApplicationContext& app_ctx)
: app_ctx_(app_ctx), module_(torch::jit::load("")) {
   // nn setup
   // assert(module != nullptr);
}

MLPipeline::~MLPipeline() {
   // notify pipeline to shut down
   shutdown_ = true;
   pipeline_.join();
}

void MLPipeline::update(const FrameBundle& frame_bundle) {
   // do update shit

   const torch::Tensor output_frame = module_.predict(frame_bundle.color_frame);

}

void MLPipeline::start_worker() {

   // do update shit

}

void MLPipeline::worker() {
   // do update shit




}


}