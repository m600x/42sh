let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/42/minishell
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +23 includes/minishell.h
badd +1 src/user-interaction/ft_word_left.c
badd +11 src/user-interaction/ft_cursor_left.c
badd +8 src/user-interaction/ft_interactive_sh.c
badd +5 src/user-interaction/ft_word_right.c
badd +18 src/user-interaction/ft_cursor_right.c
badd +7 src/user-interaction/ft_clear_line.c
badd +1 src/user-interaction/ft_line_start.c
badd +5 src/user-interaction/ft_line_end.c
badd +40 src/main/main.c
badd +12 src/builtin/builtin_exit.c
badd +1 src/user-interaction/ft_cmd.c
badd +8 src/line-editing/ft_cmd.c
badd +2 src/main/ft_cmd.c
badd +13 src/main/sig_handler.c
badd +1 src/main/prompt.c
badd +3 src/main/ft_prompt.c
badd +15 src/line-editing/ft_interactive_sh.c
badd +7 src/line-editing/ft_key_ctrl_d.c
badd +32 src/builtin/builtin_cd.c
badd +4 src/main/lib_expansion.c
badd +19 libft/src/str/ft_strjoin.c
badd +19 libft/src/str/ft_strlen.c
badd +22 libft/src/str/ft_strcat.c
badd +20 src/minishell-exec/ft_cmd.c
badd +10 src/line-editing/ft_key_enter.c
badd +16 src/line-editing/ft_history_add.c
badd +9 src/line-editing/ft_history_up.c
badd +18 src/line-editing/ft_history_down.c
badd +62 src/token/ft_tokenize.c
badd +30 src/line-editing/line-editing.h
badd +1 libft/Makefile
badd +14 Makefile
badd +18 line-editing/Makefile
badd +14 line-editing/includes/line_editing.h
badd +25 src/line-editing/includes/line_editing.h
badd +47 src/line-editing/src/ft_interactive_sh.c
badd +20 src/line-editing/src/ft_key_enter.c
badd +14 src/line-editing/ft_prompt.c
badd +22 src/line-editing/ft_tc_init.c
badd +1 libft/includes/libft.h
badd +5 libft/includes/get_next_line.h
badd +15 src/token/token_init.c
badd +69 src/token/includes/token.h
badd +15 src/token/token_recognition.c
badd +27 src/token/token_delimit.c
badd +11 src/token/token_operator_match.c
badd +7 src/token/token_next.c
badd +23 src/token/token_append.c
argglobal
silent! argdel *
edit src/token/token_next.c
set splitbelow splitright
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 13 - ((6 * winheight(0) + 20) / 41)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
13
normal! 0
tabnext 1
if exists('s:wipebuf')
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToO
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
let g:this_session = v:this_session
let g:this_obsession = v:this_session
let g:this_obsession_status = 2
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
