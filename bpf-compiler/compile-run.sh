(./a.out <$1 && echo "")  >temp.asm && ../bpf-asm/bpfasm ../bpf-asm/black.bmp ../bpf-asm/black.bmp temp.asm test.BPF && (rm temp.asm; bpfvm test.BPF; rm test.BPF)
