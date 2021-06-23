/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_define.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:29:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/06/23 09:45:36 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_DEFINE_H
# define PUSH_SWAP_DEFINE_H

# define MAX_INSTRUCTION 11

# define STR_SA		"sa"
# define STR_SB		"sb"
# define STR_SS		"ss"
# define STR_PA		"pa"
# define STR_PB		"pb"
# define STR_RA		"ra"
# define STR_RB		"rb"
# define STR_RR		"rr"
# define STR_RRA	"rra"
# define STR_RRB	"rrb"
# define STR_RRR	"rrr"

# define PRINT_SA	"sa\n"
# define PRINT_SB	"sb\n"
# define PRINT_SS	"ss\n"
# define PRINT_PA	"pa\n"
# define PRINT_PB	"pb\n"
# define PRINT_RA	"ra\n"
# define PRINT_RB	"rb\n"
# define PRINT_RR	"rr\n"
# define PRINT_RRA	"rra\n"
# define PRINT_RRB	"rrb\n"
# define PRINT_RRR	"rrr\n"

enum	e_instruction
{
	SA = 0,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
};

#endif
