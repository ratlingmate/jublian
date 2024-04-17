private:
  uint8_t case_table[256];
  unsigned needle_len_, needle_len_less1;
  size_t haystack_len;
  uint8_t shift[256];
  uint8_t jump_;
  std::vector<uint8_t> needle_;
  std::vector<uint8_t> needle_ic_;
  char *haystack_ = nullptr;
  char *current, *end, *last_found;
  bool case_sensitive_;

  void SetHayStack(std::ifstream& stream)
  {
    ClearHaystack();
    stream.seekg(0, ios::end);
    haystack_len = static_cast<size_t>(stream.tellg());
    stream.seekg(0, ios::beg);
    haystack_ = new char[haystack_len];
    stream.read(haystack_, haystack_len);
    current = haystack_;
    end = current + haystack_len;
  }

  void SetHayStack(const char* buffer, size_t buff_len)
  {
    ClearHaystack();
    this->haystack_len = buff_len;
    haystack_ = new char[buff_len];
    memcpy(haystack_, buffer, buff_len);
