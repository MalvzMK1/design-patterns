#include <iostream>
#include <string>

// Complex subsystem
class VideoFile {
public:
  std::string name;

  VideoFile(std::string name_)
    : name(name_) {}
};

class CompressionCodec {
public:
  virtual ~CompressionCodec() {}
  virtual void execute(VideoFile* videoFile) = 0;
};

class MP4CompressionCodec : public CompressionCodec {
public:
  void execute(VideoFile* videoFile) override {
    std::cout << "MP4 Compression Codec executed" << std::endl;
  };
};

class OggCompressionCodec : public CompressionCodec {
public:
  void execute(VideoFile* videoFile) override {
    std::cout << "Ogg Compression Codec executed" << std::endl;
  };
};

class CodecFactory {
public:
  CompressionCodec* create(std::string format) {
    if (format == "ogg") {
      return new OggCompressionCodec();
    }

    return new MP4CompressionCodec();
  }
};

// Facade
class VideoConverter {
public:
  VideoFile convert(std::string name, std::string format) {
    VideoFile file(name);
    CodecFactory factory;

    CompressionCodec* codec = factory.create(format);

    codec->execute(&file);

    delete codec;
    codec = nullptr;

    return file;
  }
};

int main() {
  VideoConverter videoConverter;

  VideoFile oggFile = videoConverter.convert("video_name", "ogg");
  std::cout << "Created ogg video " << oggFile.name << std::endl;

  VideoFile mp4File = videoConverter.convert("video_name", "mp4");
  std::cout << "Created mp4 video " << mp4File.name << std::endl;

  return 0;
}
